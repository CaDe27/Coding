import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
//Box and Delivery 
//http://coj.uci.cu/24h/problem.xhtml?pid=4238

public class Main{

    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() { 
            while (st == null || !st.hasMoreElements()){ 
                try{ 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e){ 
                    e.getMessage(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt(){ 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble(){ 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() { 
            String str = ""; 
            try{ 
                str = br.readLine(); 
            } 
            catch (IOException e){ 
                e.getMessage(); 
            } 
            return str; 
        } 
    }
    
    public static FastReader lect = new FastReader();
    public static long MOD = 986444689;
    public static long fact[] = new long[2*100000 + 5];
    public static int top = 0;
 
    public static void updateFact(int t){
        if(t > top){
            for(int i = top+1; i <= t; ++i)
                fact[i] = (fact[i-1]*i)%MOD;
            }
            top = t;
    }

    public static long binPow(long base, long expo){
            long r = 1;
            while (expo > 0){
                    if( (expo & 1) == 1)
                            r = (r*base) % MOD;
                    expo >>= 1;
                    base = (base * base) % MOD;
            }
            return r;
    } 

    public static long comb(int n, int k){
        return ((fact[n]* binPow(fact[k],MOD-2 ))%MOD * binPow(fact[n-k],MOD-2))%MOD;
    }

    public static int sumBossSup(int n){
        int days[] = new int[n+1];
        String aux[];
        Arrays.fill(days, 0);
        int size, sum = 0;
        
        String input = lect.nextLine();
        aux = input.split(" ");
        size = aux.length;
        for(int i = 0; i < size; ++i){
            ++days[Integer.parseInt(aux[i])];
            ++sum;
        }

        input = lect.nextLine();
        aux = input.split(" ");
        size = aux.length;
        for(int i = 0; i < size; ++i)
            sum += days[Integer.parseInt(aux[i])]==1? 1:2;
        return sum;
    }


    public static void main(String args[]) {
        fact[0] = 1;
        int t = lect.nextInt();
        for(int i = 0; i < t; ++i){
            int n, k; //days and boxes
            n = lect.nextInt();
            k = lect.nextInt();
            k-=sumBossSup(n);
            if(k < 0)
            	System.out.println(0);
            else{
	            updateFact(k+n-1);
	            System.out.println(comb(k+n-1, n-1));
            }
        }
    }

}

