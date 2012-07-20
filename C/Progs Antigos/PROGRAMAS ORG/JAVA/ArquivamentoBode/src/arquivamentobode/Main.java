/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package arquivamentobode;


import javax.swing.JFrame;

/**
 *
 * @author Leandro
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        jfPRINCIPAL prim = new jfPRINCIPAL();
        prim.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        prim.setSize( 875, 580 ); // configura o tamanho do frame
        prim.setVisible( true ); // exibe o frame
    }

}
