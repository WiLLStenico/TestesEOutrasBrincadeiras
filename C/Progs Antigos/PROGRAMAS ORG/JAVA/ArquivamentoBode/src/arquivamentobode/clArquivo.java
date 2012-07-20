/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package arquivamentobode;

import java.io.FileNotFoundException;
import java.util.Formatter;
import javax.swing.JOptionPane;

/**
 *
 * @author Leandro
 */
public class clArquivo {
    
   private Formatter saida;            // arquivo sequencial
   private String NomePaciente;

   public void abrir (String nome) {
      try
      {
         saida = new Formatter (nome);
      }
      catch (SecurityException sec1)
      {
          JOptionPane.showMessageDialog(null, " Arquivo nao pode ser aberto");
          System.exit(1);
      }
      catch (FileNotFoundException sec2)
      {
          JOptionPane.showMessageDialog(null, " Erro na abertura do arquivo");
          System.exit(1);
      }
      finally
      {
          JOptionPane.showMessageDialog(null, "arquivo criado");
      }
   }


   public void Insere_reg()
   {

       NomePaciente = "leandro";
       saida.format("%s\n",NomePaciente);

       JOptionPane.showMessageDialog(null, "informação gravada");
       

       /*
       Pessoa registro = new Pessoa("joao");
       saida.format("%s\n", registro.nome_completo);
       Pessoa registro2 = new Pessoa("pedro", "masculino");
       saida.format("%s %s\n", registro2.nome_completo, registro2.genero);

        nome_completo = nome;

        */

   }

   public void fechar (String nome)
   {
       saida.close();
       JOptionPane.showMessageDialog(null, "arquivo fechado");
   }



}
