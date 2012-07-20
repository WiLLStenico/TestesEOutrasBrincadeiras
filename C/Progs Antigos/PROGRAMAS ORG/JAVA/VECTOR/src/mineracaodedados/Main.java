/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package mineracaodedados;

import java.util.Iterator;
import java.util.Vector;
import javax.swing.JOptionPane;
/**
 *
 * @author WiLL
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Vector a =new Vector();

        a.add(new TESTE(12,1));
        //TESTE[] a = new TESTE[100];
        int re,i;



        i=0;
for(;i<50;i++){
       
     a.add(new TESTE(12,i));
    // a[i] = new TESTE(12,i);
        //re=a[i].var3;

         //JOptionPane.showMessageDialog(null,a);
}

        for(Iterator IT = a.iterator();IT.hasNext();){
            TESTE b = (TESTE)IT.next();
            JOptionPane.showMessageDialog(null,b.var3);
        }
        }

       

        // TODO code application logic here
    

}
