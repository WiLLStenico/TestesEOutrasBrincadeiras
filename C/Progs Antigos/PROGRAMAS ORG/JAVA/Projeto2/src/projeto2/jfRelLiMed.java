package projeto2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
import javax.swing.table.DefaultTableModel;


public class jfRelLiMed extends javax.swing.JFrame {

    /** Creates new form jfRelLiMed */
    public jfRelLiMed() {
        initComponents();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel2 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jtRelLiMed = new javax.swing.JTable();
        jbRelLiMedFechar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Relatório Listagem de Médicos");
        addComponentListener(new java.awt.event.ComponentAdapter() {
            public void componentShown(java.awt.event.ComponentEvent evt) {
                formComponentShown(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Times New Roman", 1, 18));
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText(":: Relatório Listagem de Médicos ::");

        jtRelLiMed.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Código", "Nome", "Nascimento", "DDD", "Telefone", "E-Mail", "CRM", "Endereço", "Número", "Bairro", "Cidade", "Estado"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false, false, false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(jtRelLiMed);
        jtRelLiMed.getColumnModel().getColumn(0).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(1).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(2).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(3).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(4).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(5).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(6).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(7).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(8).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(9).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(10).setResizable(false);
        jtRelLiMed.getColumnModel().getColumn(11).setResizable(false);

        jbRelLiMedFechar.setText("Fechar");
        jbRelLiMedFechar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbRelLiMedFecharActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 1114, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addGap(382, 382, 382)
                .addComponent(jLabel2)
                .addContainerGap(460, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(539, Short.MAX_VALUE)
                .addComponent(jbRelLiMedFechar)
                .addGap(510, 510, 510))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 451, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jbRelLiMedFechar)
                .addContainerGap(25, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void formComponentShown(java.awt.event.ComponentEvent evt) {//GEN-FIRST:event_formComponentShown

        //Vetores pacientes
       String [] aCodMed = new String[100];
       final String [] aNomeMed = new String[100];
       final String [] aNascimentoMed = new String[100];
       final String [] aDDDMed = new String[100];
       final String [] aTelefoneMed = new String[100];
       final String [] aEmailMed = new String[100];
       final String [] aCRMMed = new String[100];
       final String [] aEnderecoMed = new String[100];
       final String [] aNumeroMed = new String[100];
       final String [] aBairroMed = new String[100];
       final String [] aCidadeMed = new String[100];
       final String [] aEstadoMed = new String[100];

       int nMed = 0;

       String linhaMed;
       try {
          FileReader reader = new FileReader("Medico.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linhaMed = leitor.readLine()) != null) {

             st = new StringTokenizer(linhaMed, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Código
                dados = st.nextToken();
                System.out.println(dados);
                aCodMed[nMed] = dados;

                // Nome
                dados = st.nextToken();
                System.out.println(dados);
                aNomeMed[nMed] = dados;

                // Nascimento
                dados = st.nextToken();
                System.out.println(dados);
                aNascimentoMed[nMed] = dados;

                // DDD
                dados = st.nextToken();
                System.out.println(dados);
                aDDDMed[nMed] = dados;

                // Telefone
                dados = st.nextToken();
                System.out.println(dados);
                aTelefoneMed[nMed] = dados;

                // Email
                dados = st.nextToken();
                System.out.println(dados);
                aEmailMed[nMed] = dados;

                // Profissao
                dados = st.nextToken();
                System.out.println(dados);
                aCRMMed[nMed] = dados;

                // Endereco
                dados = st.nextToken();
                System.out.println(dados);
                aEnderecoMed[nMed] = dados;

                // Numero
                dados = st.nextToken();
                System.out.println(dados);
                aNumeroMed[nMed] = dados;

                // Bairro
                dados = st.nextToken();
                System.out.println(dados);
                aBairroMed[nMed] = dados;

                // Cidade
                dados = st.nextToken();
                System.out.println(dados);
                aCidadeMed[nMed] = dados;

                // Estado
                dados = st.nextToken();
                System.out.println(dados);
                aEstadoMed[nMed] = dados;

                nMed ++;

             }
          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }

        DefaultTableModel model = (DefaultTableModel) jtRelLiMed.getModel();
        for(int i = 0; i < aCodMed.length; i++ )
        {
            Object[] o = new Object[]{ aCodMed[i],  aNomeMed[i],  aNascimentoMed[i],  aDDDMed[i],  aTelefoneMed[i],  aEmailMed[i],  aCRMMed[i],  aEnderecoMed[i],  aNumeroMed[i],  aBairroMed[i],  aCidadeMed[i],  aEstadoMed[i] };
            model.addRow(o);
        }


    }//GEN-LAST:event_formComponentShown

    private void jbRelLiMedFecharActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbRelLiMedFecharActionPerformed
        // TODO add your handling code here:
        this.setVisible(false);
}//GEN-LAST:event_jbRelLiMedFecharActionPerformed

    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new jfRelLiMed().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton jbRelLiMedFechar;
    private javax.swing.JTable jtRelLiMed;
    // End of variables declaration//GEN-END:variables

}