package projeto2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
import javax.swing.JOptionPane;

public class jfRealizarExames_1 extends javax.swing.JFrame {

    /** Creates new form jfRealizarExames */
    public jfRealizarExames_1() {
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
        jScrollPane1 = new javax.swing.JScrollPane();
        jlMedicoExame = new javax.swing.JList();
        jScrollPane2 = new javax.swing.JScrollPane();
        jlPacienteExame = new javax.swing.JList();
        jbCadRExame = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jScrollPane3 = new javax.swing.JScrollPane();
        jlSintomaExame = new javax.swing.JList();
        jScrollPane4 = new javax.swing.JScrollPane();
        jlExameExame = new javax.swing.JList();
        jbCancelalRExame = new javax.swing.JButton();
        jtDiagnosticoExame = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Realizar Exames");
        addComponentListener(new java.awt.event.ComponentAdapter() {
            public void componentShown(java.awt.event.ComponentEvent evt) {
                formComponentShown(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Times New Roman", 1, 18));
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText(":: Realizar Exames ::");

        jLabel1.setText("Médico:");

        jScrollPane1.setViewportView(jlMedicoExame);

        jScrollPane2.setViewportView(jlPacienteExame);

        jbCadRExame.setText("Cadastrar Exame");
        jbCadRExame.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbCadRExameActionPerformed(evt);
            }
        });

        jLabel3.setText("Paciente:");

        jLabel4.setText("Sintoma:");

        jLabel5.setText("Exame:");

        jScrollPane3.setViewportView(jlSintomaExame);

        jScrollPane4.setViewportView(jlExameExame);

        jbCancelalRExame.setText("Cancelar");
        jbCancelalRExame.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbCancelalRExameActionPerformed(evt);
            }
        });

        jtDiagnosticoExame.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jtDiagnosticoExameActionPerformed(evt);
            }
        });

        jLabel6.setText("Diagnóstico:");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                            .addGap(35, 35, 35)
                            .addComponent(jLabel6)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(jtDiagnosticoExame))
                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                            .addGap(202, 202, 202)
                            .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 198, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                            .addGap(25, 25, 25)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addComponent(jLabel1, javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(layout.createSequentialGroup()
                                    .addGap(20, 20, 20)
                                    .addComponent(jLabel3))
                                .addGroup(layout.createSequentialGroup()
                                    .addGap(18, 18, 18)
                                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(layout.createSequentialGroup()
                                    .addGap(6, 6, 6)
                                    .addComponent(jLabel4))
                                .addGroup(layout.createSequentialGroup()
                                    .addGap(14, 14, 14)
                                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 126, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGap(10, 10, 10)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(layout.createSequentialGroup()
                                    .addGap(6, 6, 6)
                                    .addComponent(jLabel5))
                                .addGroup(layout.createSequentialGroup()
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 136, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(189, 189, 189)
                        .addComponent(jbCadRExame)
                        .addGap(18, 18, 18)
                        .addComponent(jbCancelalRExame)))
                .addContainerGap(39, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2)
                .addGap(27, 27, 27)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4)
                    .addComponent(jLabel5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane4)
                    .addComponent(jScrollPane3)
                    .addComponent(jScrollPane2)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 199, Short.MAX_VALUE))
                .addGap(26, 26, 26)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(jtDiagnosticoExame, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jbCancelalRExame)
                    .addComponent(jbCadRExame))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void formComponentShown(java.awt.event.ComponentEvent evt) {//GEN-FIRST:event_formComponentShown

       //Vetores médicos
       String [] aCodMed = new String[100];
       final String [] aNomeMed = new String[100];
       int nMed = 0;

       //Vetores pacientes
       String [] aCodPaci = new String[100];
       final String [] aNomePaci = new String[100];
       int nPaci = 0;

       //Vetores sintomas
       String [] aCodSint = new String[100];
       final String [] aNomeSint = new String[100];
       int nSint = 0;

       //Vetores exames
       String [] aCodExa = new String[100];
       final String [] aDescExa = new String[100];
       int nExa = 0;


       String linhaMed;
       try {
          FileReader reader = new FileReader("Medico.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linhaMed = leitor.readLine()) != null) {

             st = new StringTokenizer(linhaMed, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);
                aCodMed[nMed] = dados;

                // Campo 2
                dados = st.nextToken();
                System.out.println(dados);
                aNomeMed[nMed] = dados;

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

                nMed ++;

             }
          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }

       jlMedicoExame.setModel(new javax.swing.AbstractListModel() {
       public int getSize() { return aNomeMed.length; }
       public Object getElementAt(int i) { return aNomeMed[i]; }
       });



       String linhaPaci;
       try {
          FileReader reader = new FileReader("Paciente.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linhaPaci = leitor.readLine()) != null) {

             st = new StringTokenizer(linhaPaci, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);
                aCodPaci[nPaci] = dados;

                // Campo 2
                dados = st.nextToken();
                System.out.println(dados);
                aNomePaci[nPaci] = dados;

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

                nPaci ++;

             }
          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }

       jlPacienteExame.setModel(new javax.swing.AbstractListModel() {
            public int getSize() { return aNomePaci.length; }
            public Object getElementAt(int i) { return aNomePaci[i]; }
        });


       //Lê arquivo sintomas
       String linhaSint;
       try {
          FileReader reader = new FileReader("Sintoma.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linhaSint = leitor.readLine()) != null) {

             st = new StringTokenizer(linhaSint, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);
                aCodSint[nSint] = dados;

                // Campo 2
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

       jlSintomaExame.setModel(new javax.swing.AbstractListModel() {
            public int getSize() { return aNomeSint.length; }
            public Object getElementAt(int i) { return aNomeSint[i]; }
        });





       //Lê arquivo Exames
       String linhaExa;
       try {
          FileReader reader = new FileReader("Exame.txt");
          BufferedReader leitor = new BufferedReader(reader);
          StringTokenizer st = null;

          while ((linhaExa = leitor.readLine()) != null) {

             st = new StringTokenizer(linhaExa, "\t");
             String dados = null;

             while (st.hasMoreTokens()) {

                // Campo 1
                dados = st.nextToken();
                System.out.println(dados);
                aCodExa[nExa] = dados;

                // Campo 2
                dados = st.nextToken();
                System.out.println(dados);
                aDescExa[nExa] = dados;

                // Campo 3
                dados = st.nextToken();
                System.out.println(dados);
                aNomeSint[nSint] = dados;


                nExa ++;

             }
          }

          leitor.close();
          reader.close();

       } catch (Exception e) {
          e.printStackTrace();
       }

       jlExameExame.setModel(new javax.swing.AbstractListModel() {
            public int getSize() { return aDescExa.length; }
            public Object getElementAt(int i) { return aDescExa[i]; }
        });

    }//GEN-LAST:event_formComponentShown

    private void jbCadRExameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbCadRExameActionPerformed
       
        String MedicoSelec = (String) jlMedicoExame.getSelectedValue();
        String PacienteSelec = (String) jlPacienteExame.getSelectedValue();
        String SintomaSelec = (String) jlSintomaExame.getSelectedValue();
        String ExameSelec = (String) jlExameExame.getSelectedValue();
        String DiagnosticoExame = jtDiagnosticoExame.getText();

        //Verifica qual é o próximo código
        clCodProximoRExame CodProximoRExame = new clCodProximoRExame();
        String CodigoRExame = CodProximoRExame.RealizarExame();
        int nCodigoRExame = 0;

        if (CodigoRExame ==  null){
           CodigoRExame = "1";
        }
        else {
           nCodigoRExame = Integer.parseInt(CodigoRExame) + 1;
        }

         clArquivoRExame _file = new clArquivoRExame("RExame.txt");
        _file.openFile();
        _file.writeInFile(nCodigoRExame + "\t" + MedicoSelec + "\t" + PacienteSelec + "\t" + SintomaSelec + "\t" + ExameSelec + "\t" + DiagnosticoExame + "\r\n");
        _file.closeFile();
        
}//GEN-LAST:event_jbCadRExameActionPerformed

    private void jbCancelalRExameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbCancelalRExameActionPerformed
        this.setVisible(false);
    }//GEN-LAST:event_jbCancelalRExameActionPerformed

    private void jtDiagnosticoExameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jtDiagnosticoExameActionPerformed
}//GEN-LAST:event_jtDiagnosticoExameActionPerformed

    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new jfRealizarExames().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JButton jbCadRExame;
    private javax.swing.JButton jbCancelalRExame;
    private javax.swing.JList jlExameExame;
    private javax.swing.JList jlMedicoExame;
    private javax.swing.JList jlPacienteExame;
    private javax.swing.JList jlSintomaExame;
    private javax.swing.JTextField jtDiagnosticoExame;
    // End of variables declaration//GEN-END:variables

}