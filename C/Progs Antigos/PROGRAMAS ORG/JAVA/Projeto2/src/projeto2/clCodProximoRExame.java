package projeto2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.StringTokenizer;


public class clCodProximoRExame {


    private String CodigoRExame;



    public String RealizarExame() {
       String linha = null;


       File file = new File("RExame.txt");

       if (!file.exists()) {
           return "0";
       }



       try {
          FileReader reader = new FileReader("RExame.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linha = leitor.readLine()) != null) {

             st = new StringTokenizer(linha, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);

                CodigoRExame = dados;

                // Campo 2
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 3
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 4
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 5
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 6
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


       return CodigoRExame;
    }




}
