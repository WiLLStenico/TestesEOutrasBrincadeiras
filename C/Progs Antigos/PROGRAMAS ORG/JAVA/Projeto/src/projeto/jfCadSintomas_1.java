/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * jfCadSintomas.java
 *
 * Created on 24/05/2009, 02:21:16
 */

package projeto;

import javax.swing.JOptionPane;

/**
 *
 * @author Leandro
 */
public class jfCadSintomas_1 extends javax.swing.JFrame {
    private String DescricaoSintoma;
    private String CodigoSintoma;
    private int nCodigoSintoma;

    /** Creates new form jfCadSintomas */
    public jfCadSintomas_1() {
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
        jLabel1 = new javax.swing.JLabel();
        jbCadastrarSintoma = new javax.swing.JButton();
        jbCancelarSintoma = new javax.swing.JButton();
        jtDescricaoSintoma = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cadastro de Sintomas");

        jLabel2.setFont(new java.awt.Font("Times New Roman", 1, 18));
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText(":: Cadastro de Sintomas ::");

        jLabel1.setText("Descrição:");

        jbCadastrarSintoma.setText("Cadastrar");
        jbCadastrarSintoma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbCadastrarSintomaActionPerformed(evt);
            }
        });

        jbCancelarSintoma.setText("Cancelar");
        jbCancelarSintoma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbCancelarSintomaActionPerformed(evt);
            }
        });

        jtDescricaoSintoma.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jtDescricaoSintomaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(45, 45, 45)
                        .addComponent(jbCadastrarSintoma)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jbCancelarSintoma))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(32, 32, 32)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel2)
                            .addComponent(jtDescricaoSintoma, javax.swing.GroupLayout.PREFERRED_SIZE, 184, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(32, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2)
                .addGap(18, 18, 18)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jtDescricaoSintoma, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(31, 31, 31)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jbCadastrarSintoma)
                    .addComponent(jbCancelarSintoma))
                .addContainerGap(36, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jbCadastrarSintomaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbCadastrarSintomaActionPerformed
        // TODO add your handling code here:

        DescricaoSintoma       = jtDescricaoSintoma.getText();

        if (DescricaoSintoma.equals("")) {
            JOptionPane.showMessageDialog(null, "Favor preencher o sintoma!");
        }
        else {

            //Verifica qual é o próximo código
            clCodProximoSintoma CodProximoSintoma = new clCodProximoSintoma();
            CodigoSintoma = CodProximoSintoma.sintoma();

            if (CodigoSintoma ==  null){
                CodigoSintoma = "1";
            }
            else {
                nCodigoSintoma = Integer.parseInt(CodigoSintoma) + 1;
            }

            clArquivoSintoma _file = new clArquivoSintoma("Sintoma.txt");
            _file.openFile();
            _file.writeInFile(nCodigoSintoma + "\t" + DescricaoSintoma + "\r\n");
            _file.closeFile();

            jtDescricaoSintoma.setText("");







        }




}//GEN-LAST:event_jbCadastrarSintomaActionPerformed

    private void jbCancelarSintomaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbCancelarSintomaActionPerformed
        // TODO add your handling code here:
        this.setVisible(false);
    }//GEN-LAST:event_jbCancelarSintomaActionPerformed

    private void jtDescricaoSintomaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jtDescricaoSintomaActionPerformed
        // TODO add your handling code here:
}//GEN-LAST:event_jtDescricaoSintomaActionPerformed

    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new jfCadSintomas().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JButton jbCadastrarSintoma;
    private javax.swing.JButton jbCancelarSintoma;
    private javax.swing.JTextField jtDescricaoSintoma;
    // End of variables declaration//GEN-END:variables

}
