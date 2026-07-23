public class PowerOfTwo{
    public static void main(String[] args) {
        
    }

    public static boolean  PowerOfTwo(int n){
        if(n == 1){
            return true;
        }

        if(n <= 0){
            return false;
        }

        return PowerOfTwo(n/2);
    }
}