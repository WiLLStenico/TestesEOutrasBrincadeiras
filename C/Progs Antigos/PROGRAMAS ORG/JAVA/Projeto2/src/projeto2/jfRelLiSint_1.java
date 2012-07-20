package projeto2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
import javax.swing.table.DefaultTableModel;

public class jfRelLiSint_1 extends javax.swing.JFrame {

           //Vetores pacientes
       String [] aCodSint = new String[100];
       final String [] aNomeSint = new String[100];


    /** Creates new form jfRelLiSint */
    public jfRelLiSint_1() {
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
        jtRelLiSint = new javax.swing.JTable();
        jbRelLiSintFechar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Relatório Listagem de Sintomas");
        addComponentListener(new java.awt.event.ComponentAdapter() {
            public void componentShown(java.awt.event.ComponentEvent evt) {
                formComponentShown(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Times New Roman", 1, 18));
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText(":: Relatório Listagem de Sintomas ::");

        jtRelLiSint.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Código", "Descrição"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(jtRelLiSint);
        jtRelLiSint.getColumnModel().getColumn(0).setResizable(false);
        jtRelLiSint.getColumnModel().getColumn(1).setResizable(false);

        jbRelLiSintFechar.setText("Fechar");
        jbRelLiSintFechar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbRelLiSintFecharActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addGroup(layout.createSequentialGroup()
                .addGap(72, 72, 72)
                .addComponent(jLabel2))
            .addGroup(layout.createSequentialGroup()
                .addGap(194, 194, 194)
                .addComponent(jbRelLiSintFechar))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(4, 4, 4)
                .addComponent(jLabel2)
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jbRelLiSintFechar)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jbRelLiSintFecharActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbRelLiSintFecharActionPerformed
        // TODO add your handling code here:
        this.setVisible(false);
}//GEN-LAST:event_jbRelLiSintFecharActionPerformed

    private void formComponentShown(java.awt.event.ComponentEvent evt) {//GEN-FIRST:event_formComponentShown

       int nSint = 0;

       String linhaSint;
       try {
          FileReader reader = new FileReader("Sintoma.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linhaSint = leitor.readLine()) != null) {

             st = new StringTokenizer(linhaSint, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Código
                dados = st.nextToken();
                System.out.println(dados);
                aCodSint[nSint] = dados;

                // Descrição
                dados = st.nextToken();
                System.out.println(dados);
                aNomeSint[nSint] = dados;

                nSint ++;

             }
          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }



        DefaultTableModel model = (DefaultTableModel) jtRelLiSint.getModel();
        for(int i = 0; i < aCodSint.length; i++ )
        {
            Object[] o = new Object[]{ aCodSint[i],  aNomeSint[i] };
            model.addRow(o);
        }

    }//GEN-LAST:event_formComponentShown

    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new jfRelLiSint().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton jbRelLiSintFechar;
    private javax.swing.JTable jtRelLiSint;
    // End of variables declaration//GEN-END:variables

}
