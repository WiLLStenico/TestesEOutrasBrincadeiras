package projeto2;

import javax.swing.JFrame;

public class Main_1 {

    public static void main(String[] args) {
        // Chama o formulário principal.
        jfPRINCIPAL prim = new jfPRINCIPAL();
        prim.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        prim.setSize( 400, 300 ); // configura o tamanho do frame
        prim.setVisible( true ); // exibe o frame
    }

}
