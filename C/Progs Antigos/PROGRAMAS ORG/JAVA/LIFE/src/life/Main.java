/* SISTEMA DE TESTE DE RECURSOS DA ORIENTACAO A OBJETOS EM JAVA */

package life;
import javax.swing.JOptionPane;
import java.util.Date;

public class Main {

    public static void main(String[] args) {
        Pessoa a,b;
        Residencia casa1;
        

        casa1 = new Residencia();
        String name = JOptionPane.showInputDialog("Digite nome de uma pessoa");
        a = new Pessoa(name);
        b = new Pessoa("Ze");
        casa1.moradores = new Pessoa[5];
        casa1.moradores[0] = a;
        casa1.moradores[1] = b;
        casa1.nro_moradores = 2;
        casa1.endereco = JOptionPane.showInputDialog("Digite seu endereço");
        a.morador_de = casa1;
        casa1.engenheiro = a;
        a.genero="masculino";
        a.altura=1.89f;
        a.data_nasc= new Date("1988/12/10");
        JOptionPane.showMessageDialog(null, "NASCEU: " + a.nome_completo+
                "\n "+ a.genero+" "+String.valueOf(a.altura)+
                " "+ String.valueOf((a.data_nasc))+
                "\n morador da "+ casa1.endereco);

    }

}
