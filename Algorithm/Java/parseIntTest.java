package Algorithm.Java;

/**
 * parseIntTest
 */
public class parseIntTest {

    public static void main(String[] args) {
        String temp="a.b.v....";
        String[] str=temp.split("\\.");
        System.out.println(str.length);
    }
}