package projeto2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;


//Adiciona em txt
public class clArquivoSintoma {

    private String _fileName;

    FileReader _reader;
    FileWriter _writer;
    BufferedReader _breader;
    File _fp;

    public clArquivoSintoma(String nome)
    {
        _fileName = nome ;
    }

    public void openFile()
    {

        if(_fileName.equals("") || _fileName == null)
            return;

        _fp = new File(_fileName);

        if(!_fp.exists())
        {
            System.out.println("Arquivo nao existe");
            //return;
        }
        if(!_fp.canWrite())
        {
            System.out.println("Você nao possui permissão para isto");
            //return;
        }


        try
        {
            _fp.createNewFile();
            _reader = new FileReader(_fp);
            _writer = new FileWriter(_fp, true);
            _breader = new BufferedReader( _reader );
        }
        catch(Exception e)
        {
        }

    }

    public void writeInFile(String _data)
    {
        try
        {
            if(!_data.contains("\r\n"))
                _data = _data + "\r\n";
            _writer.write(_data);
            _writer.flush();
        }
        catch(Exception e)
        {
        }
    }

    public void closeFile()
    {

    }


}
