/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package socketsjava;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;

/**
 *
 * @author leandro
 */
public class ClienteThread extends Thread {
    
    private Nim frame;


    public ClienteThread(Nim frame) {

        this.frame=frame;

    }


    @Override
    public void run() {

        // Recebe msg, atualiza painel.
        while (true) {
            try {
                
                String mensagem = this.frame.tcpclient.readMessage();
                System.out.println("["+ mensagem + "]");


                if(mensagem.equals("1")) {
                    this.frame.Marcar(true);
                }
                else if (mensagem.equals("0")) {
                    this.frame.Marcar(false);
                }



            } catch (IOException ex) {
                Logger.getLogger(ClienteThread.class.getName()).log(Level.SEVERE, null, ex);
            }

        }

    }




}
