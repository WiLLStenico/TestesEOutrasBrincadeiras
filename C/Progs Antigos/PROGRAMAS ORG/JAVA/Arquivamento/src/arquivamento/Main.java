package arquivamento;
import javax.swing.JOptionPane;
import javax.swing.JFrame;
public class Main {

    
    public static void main(String[] args) {
         Manipulacao prim = new Manipulacao(); // cria LabelFrame
         prim.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
         prim.setSize( 875, 580 ); // configura o tamanho do frame
         prim.setVisible( true ); // exibe o frame
     }
}
