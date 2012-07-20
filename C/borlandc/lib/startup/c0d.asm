;[]------------------------------------------------------------[]
;|      C0D.ASM -- Start Up Code For Windows DLLs               |
;[]------------------------------------------------------------[]

;
;       C/C+iority],ah     ;check the priority
                jb      @@Next                  ;too low?  skip
                mov     ah,es:[bx.priority]     ;keep priority
                mov     dx,bx                   ;keep index in dx
@@Next:         add     bx,SIZE SE              ;bx = next item in table
                jmp     @@TopOfTable

@@EndOfTable:   cmp     dx,di                   ;did we exhaust the table?
                je      @@Done                  ;yes, quit
                mov     bx,dx                   ;bx = highest priority item
                cmp     es:[bx.calltype],PNEAR  ;is it near or far?
                mov     es:[bx.calltype],NOTUSED;wipe the call type
                push    es                      ;save es
                je      @@NearCall

@@FarCall:      call    DWORD PTR es:[bx.addrlow]
                pop     es                      ;restore es
                jmp     short @@Start

@@NearCall:     call    WORD PTR es:[bx.addrlow]
                pop     es                      ;restore es
                jmp     short @@Start

@@Done:         ret
                endp

;------------------------------------------------------------------

ErrorDisplay    PROC    NEAR
                mov     ah, 040h
                mov     bx, 2
                int     021h
                ret
ErrorDisplay    ENDP

_abort          PROC    DIST
                PUBLIC  _abort
                mov     cx, lgth_abortMSG
                mov     dx, offset DGROUP: abortMSG
MsgExit3        label   near
                mov     ds, cs: DGROUP@@
                call    ErrorDisplay
CallExit3       label   near
                mov     ax, 3
                push    ax
                call    __exit           ; _exit(3);
                ENDP

; The DGROUP@ variable is used to reload DS with DGROUP

PubSym@         DGROUP@, <dw    ?>, __PASCAL__



; __MMODEL is used to determine the memory model or the default
; pointer types at run time.

                public __MMODEL
__MMODEL        dw      MMODEL

_TEXT           ENDS

                SUBTTL  Start Up Data Area
                PAGE
;[]------------------------------------------------------------[]
;|      Start Up Data Area                                      |
;|                                                              |
;|      WARNING         Do not move any variables in the data   |
;|                      segment unless you're absolutely sure   |
;|                      that it does not matter.                |
;[]------------------------------------------------------------[]

_DATA           SEGMENT

;       Magic symbol used by the debug info to locate the data segment
                public DATASEG@
DATASEG@        label   byte

;       The CopyRight string must NOT be moved or changed without
;       changing the null pointer check logic

CopyRight       db      4 dup(0)
                db      'Borland C++ - Copyright 1991 Borland Intl.',0
lgth_CopyRight  equ     $ - CopyRight

IF      LDATA  EQ  false
IFNDEF  __TINY__
CheckSum        equ     00D5Ch
NullCheck       db      'Null pointer assignment', 13, 10
lgth_NullCheck  equ     $ - NullCheck
ENDIF
ENDIF

ZeroDivMSG      db      'Divide error', 13, 10
lgth_ZeroDivMSG equ     $ - ZeroDivMSG

abortMSG        db      'Abnormal program termination', 13, 10
lgth_abortMSG   equ     $ - abortMSG

;
;                       Interrupt vector save areas
;
;       Interrupt vectors 0,4,5 & 6 are saved at startup and then restored
;       when the program terminates.  The signal/raise functions might
;       steal these vectors during execution.
;
;       Note: These vectors save area must not be altered
;             without changing the save/restore logic.
;
PubSym@         _Int0Vector     <dds must BE AWARE that signal() functions which take these
;       vectors will be deactivated if the keep() function is executed.
;       If a TSR wants to use the signal functions when it is active it
;       will have to save/restore these vectors itself when activated and
;       deactivated.
;--------------------------------------------------------------------------
__restorezero   PROC    DIST
                PUBLIC  __restorezero
IFDEF   __HUGE__
                push    ds
                mov     ds, cs: DGROUP@@
ENDIF
                push    ds
                mov     ax, 2500h
                lds     dx, _Int0Vector@
                int     21h
                pop     ds

                push    ds
                mov     ax, 2504h
                lds     dx, _Int4Vector@
                int     21h
                pop     ds

                push    ds
                mov     ax, 2505h
                lds     dx, _Int5Vector@
                int     21h
                pop     ds

IFNDEF   __HUGE__
                push    ds
ENDIF
                mov     ax, 2506h
                lds     dx, _Int6Vector@
                int     21h
                pop     ds

                ret
                ENDP

;------------------------------------------------------------------
;  Loop through a startup/exit (SE) table,
;  calling functions in order of priority.
;  ES:SI is assumed to point to the beginning of the SE table
;  ES:DI is assumed to point to the end of the SE table
;  First 64 priorities are reserved by Borland
;------------------------------------------------------------------
PNEAR           EQU     0
PFAR            EQU     1
NOTUSED         EQU     0ffh

SE              STRUC
calltype        db      ?                       ; 0=near,1=far,ff=not used
priority        db      ?                       ; 0=highest,ff=lowest
addrlow         dw      ?
addrhigh        dw      ?
SE              ENDS

Initialize      proc near
@@Start:        mov     ax,100h                 ;start with lowest priority
                mov     dx,di                   ;set sentinel to end of table
                mov     bx,si                   ;bx = start of table

@@TopOfTable:   cmp     bx,di                   ;and the end of the table?
                je      @@EndOfTable            ;yes, exit the loop
                cmp     es:[bx.calltype],NOTUSED;check the call type
                je      @@Next
                mov     cl, es:[bx.priority]    ;move priority to CX
                xor     ch, ch
                cmp     cx,ax                   ;check the priority
                jae     @@Next                  ;too high?  skip
                mov     ax,cx                   ;keep priority
                mov     dx,bx                   ;keep index in dx
@@Next:         add     bx,SIZE SE              ;bx = next item in table
                jmp     @@TopOfTable

@@EndOfTable:   cmp     dx,di                   ;did we exhaust the table?
                je      @@Done                  ;yes, quit
                mov     bx,dx                   ;bx = highest priority item
                cmp     es:[bx.calltype],PNEAR  ;is it near or far?
                mov     es:[bx.calltype],NOTUSED;wipe the call type
                push    es                      ;save es
                je      @@NearCall

@@FarCall:      call    DWORD PTR es:[bx.addrlow]
                pop     es                      ;restore es
                jmp     short @@Start

@@NearCall:     call    WORD PTR es:[bx.addrlow]
                pop     es                      ;restore es
                jmp     short @@Start

@@Done:         ret
                endp

Cleanup         proc near
@@Start:        mov     ah,0                    ;start with highest priority
                mov     dx,di                   ;set sentinel to end of table
                mov     bx,si                   ;bx = start of table

@@TopOfTable:   cmp     bx,di                   ;and the end ot)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           