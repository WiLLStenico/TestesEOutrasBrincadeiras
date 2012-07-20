/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package projeto;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.StringTokenizer;
import javax.swing.JOptionPane;

/**
 *
 * @author Leandro
 */
public class clCodProximoSintoma {

    private String CodigoSintoma;


    public String sintoma() {
       String linha = null;


       File file = new File("Sintoma.txt");

       if (!file.exists()) {
           return "0";
       }



       try {
          FileReader reader = new FileReader("Sintoma.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linha = leitor.readLine()) != null) {

             st = new StringTokenizer(linha, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);

                CodigoSintoma = dados;

                // Campo 2
                dados = st.nextToken();
                System.out.println(dados);

                System.out.println("-------");

             }

          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }


       return CodigoSintoma;
    }



}
