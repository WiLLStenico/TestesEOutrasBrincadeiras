package apriori;


import javax.swing.JOptionPane;
import com.sun.xml.internal.ws.util.StringUtils;
import java.io.BufferedReader;
import java.io.FileReader;
import java.lang.String;
import java.util.StringTokenizer;


public class Abre_Arquivo {

    String linha=null;
    String campo1,campo2,campo3,campo4,campo5;

    



    Abre_Arquivo(){

        JOptionPane.showMessageDialog(null,"Arquivo a ser Importado esta no C:/ e se Chama Dados_para_Mineracao.csv");

        //ABRE ARQUIVO!!!!!!!



         try {
          FileReader reader = new FileReader("C:/Dados_para_MineracaoCSV.csv");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;
          boolean verif_linha_1 = false;


         while ((linha = leitor.readLine()) != null) {

                st = new StringTokenizer(linha, ";");
                String Str_dados_importados = null;

                if(verif_linha_1==false){


                    campo1 = st.nextToken();
                    campo2 = st.nextToken();
                    campo3 = st.nextToken();
                    campo4 = st.nextToken();
                    campo5 = st.nextToken();

                    System.out.println(campo1);
                    System.out.println(campo2);
                    System.out.println(campo3);
                    System.out.println(campo4);
                    System.out.println(campo5);

                    System.out.println("____________________________");
                    //Str_dados_importados = st.nextToken();
                    verif_linha_1=true;
                }


                while (st.hasMoreTokens()) {


                Str_dados_importados = st.nextToken();
                System.out.println(Str_dados_importados);
                //System.out.println("OUTRO CAMPO!!");


             }

          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }


    }

}
