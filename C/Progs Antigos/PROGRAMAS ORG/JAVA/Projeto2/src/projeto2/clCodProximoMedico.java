package projeto2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.StringTokenizer;


public class clCodProximoMedico {

    private String CodigoMedico;


    public String medico() {
       String linha = null;


       File file = new File("Medico.txt");

       if (!file.exists()) {
           return "0";
       }



       try {
          FileReader reader = new FileReader("Medico.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linha = leitor.readLine()) != null) {

             st = new StringTokenizer(linha, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);

                CodigoMedico = dados;

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

                // Campo 7
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 8
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 9
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 10
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 11
                dados = st.nextToken();
                System.out.println(dados);

                // Campo 12
                dados = st.nextToken();
                System.out.println(dados);

             }

          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }

       //JOptionPane.showMessageDialog(null, CodigoPaciente);


       return CodigoMedico;
    }



}
