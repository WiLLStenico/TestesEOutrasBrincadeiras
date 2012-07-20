package arquivamento;
import java.util.Date;
import java.io.Serializable;

/** Classe de Pessoas viventes em uma comunidade
 * @author Prof Luiz Camolesi Jr.
 * @version 1.0 -- 27-fev-2009
 */
public class Pessoa {
    
    // atributos publicos
    /** Nome Completo de uma pessoa **/
    public String nome_completo;

    /** Data de nascimento de uma pessoa **/
    public Date data_nasc;
    public String genero;             // m- masculino,  f- feminino
    public float altura;
   //public Residencia morador_de;
    
    // atributos privados
       
    // métodos publicos
    
    // métodos construtores
    public Pessoa () {
        this.nome_completo = "Desconhecido";
    }
    public Pessoa (String nome) {
        nome_completo = nome;
    }
    public Pessoa (String nome, String sexo) {
        nome_completo = nome;
        genero = sexo;
    }
        
    // métodos publicos
    public Date get_aniv() {
        return data_nasc;
    }
        
}

