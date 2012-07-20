package teste;

import com.sun.xml.internal.ws.util.StringUtils;
//import org.apache.commons.lang.StringUtils;

public class teste  {

    public static void main(String[] args) {

        String exemplo = "a|b|c|d|e|f";

        String[] temp = StringUtils.split(exemplo, "|");

        for (int i = 0; i < temp.length; i++) {

            System.out.println( temp[i]);
        }

        String exemplo2 = StringUtils.replace(exemplo, "a", "A");

        System.out.println(exemplo2);
    }
}
