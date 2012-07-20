package projeto2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.StringTokenizer;

//Lê o arquivo para saber qual é o próximo código
public class clCodProximoExame {

    private String CodigoExame;


    public String exame() {
       String linha = null;


       File file = new File("Exame.txt");

       if (!file.exists()) {
           return "0";
       }



       try {
          FileReader reader = new FileReader("Exame.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linha = leitor.readLine()) != null) {

             st = new StringTokenizer(linha, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);

                CodigoExame = dados;

                // Campo 2
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 3
                dados = st.nextToken();
                System.out.println(dados);

             }

          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }


       return CodigoExame;

    }

}
