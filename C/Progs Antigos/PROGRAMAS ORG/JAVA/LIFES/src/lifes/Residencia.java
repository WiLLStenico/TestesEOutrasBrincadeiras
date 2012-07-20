
package lifes;

public class Residencia {

    // ============================================= atributos públicos
    /** endereço **/
    public String endereco;
    // quantidade de pessoas que moram na casa
    public int nro_moradores;
    // referencias as pessoas moradoras
    public Pessoa moradores[];
    // engenheiro responsavel
    public Pessoa engenheiro;
    // estado de habitado
    public boolean habitado=false;
    // limite predefinido de andares para todas residencias, pode ser alterado
    public static int max_pav = 3;
    // finalidade do imovel predefinida e não poder ser alterada
    public static final String finalidade = "moradia";

    // ============================================== atributos privados
    // valor venal do imovel
    private float valor;

    // ============================================== metodos públicos
    // atribuir engenheiro

    // ============================================== métodos privados


    
    // ============================================== métodos de inicialização
    static {
        
    }
}
