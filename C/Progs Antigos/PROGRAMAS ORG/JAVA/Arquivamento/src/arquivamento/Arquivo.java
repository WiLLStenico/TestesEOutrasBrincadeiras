package arquivamento;
// Demonstrando a classe File.
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import java.io.ObjectOutputStream;
import java.util.Formatter;  /* direcionador de saida */
public class Arquivo
{
   private Formatter saida;            // arquivo sequencial
   //private ObjectOutputStream saida2;  // arquivo serializavel
   public void fechar (String nome)
   {
       saida.close();
       JOptionPane.showMessageDialog(null, "arquivo fechado");
   }
   public void abrir (String nome)
   {
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
       Pessoa registro = new Pessoa("joao");
       saida.format("%s\n", registro.nome_completo);
       Pessoa registro2 = new Pessoa("pedro", "masculino");
       saida.format("%s %s\n", registro2.nome_completo, registro2.genero);
   }
   /*public void Insere_obj()
   {
       Pessoa objeto = new Pessoa("joao");
        try {
            saida2.writeObject(objeto);
        } catch (IOException ex) {
              JOptionPane.showMessageDialog(null, "inserção 1 nao realizada");
        }
       Pessoa objeto2 = new Pessoa("pedro", "masculino");
        try {
            saida2.writeObject(objeto2);
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null, "inserção 2 nao realizada");
        }
   }*/

   // exibe informa��es sobre o arquivo que o usu�rio especifica
   public void analise( String path )
   {
      // cria o objeto File com base na entrada de usu�rio
      File arq = new File( path );

      if (arq.exists()) // se o nome existir, gera sa�da das informa��es sobre ele
      {
         // exibe informa��es sobre o arquivo (ou diret�rio)
          JOptionPane.showMessageDialog(null, arq.getName()+ " exists\n" +
            ( arq.isFile() ? "é um arquivo\n" : "não é um arquivo\n" )+
            ( arq.isDirectory() ? "é um diretorio\n" : "não é um diretorio\n" )+
            ( arq.isAbsolute() ? "é um caminho absoluto\n" : "não é um caminho absoluto\n" )+
            "\nTamanho: " + String.valueOf(arq.length())+
            "\nCaminho: " + String.valueOf(arq.getPath())+
            "\nCaminho absoluto: " + String.valueOf(arq.getAbsolutePath())+
            "\nPasta pai: " + arq.getParent());

         if (arq.isDirectory()) // listagem de diretorio de saida
         {
            String directory[] = arq.list();
            System.out.println( "\n\nDirectory contents:\n" );
   
            for ( String directoryName : directory )
               System.out.printf( "%s\n", directoryName );
         } // fim do else
      } // fim do if externo
      else // nao for arquivo ou diret�rio, gera sa�da da mensagem de erro
      {
         JOptionPane.showMessageDialog(null, arq.getName()+ " -- Arquivo nao exists\n");
      } // fim do else
   } // fim do m�todo analyzePath
} // fim da classe Arquivo
