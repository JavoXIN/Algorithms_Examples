import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main { 
   public static void main(String args[]) throws IOException{
           BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             int num = Integer.parseInt(br.readLine());
             int[] num_arr = new int[num];
             for(int i = 0 ; i < num_arr.length; i ++) {num_arr[i] = Integer.parseInt(br.readLine());}
             int temp = 0;
             for(int i = 0 ; i < num_arr.length ; i ++) {for(int j = i+1 ; j < num_arr.length; j++) {if(num_arr[i] > num_arr[j]) {
                   temp = num_arr[i];
                   num_arr[i] = num_arr[j];
                   num_arr[j] = temp;}}}
             for(int i : num_arr)
                System.out.println(i);
             }
}