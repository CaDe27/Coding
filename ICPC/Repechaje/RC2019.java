import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

//Repechaje ICPC Latinoamerica 2019
//Problema C 
//Disponible en: https://www.juezguapa.com/problemas/enunciado/calculate-taxes-for-planet-e

//usamos la clase BigInteger y BigDecimal para manejar numeros tan grandes
class Main{
    
    public static void main(String args[]){
        Scanner lect = new Scanner(System.in);
        
        //aux la utilizamos para leer los datos
        BigInteger total = BigInteger.ZERO;
        BigDecimal aux;
        int n;
        
        n = lect.nextInt();
        //multiplicamos por 10^5 para manejar los decimales 
        //como enteros y poder usar funciones como mod
        
        for(int i = 0;  i < n; ++i){
            aux = lect.nextBigDecimal();
            total = total.add( (aux.multiply(BigDecimal.TEN.pow(5))).toBigInteger());
        }
        
        // a las categorias tambien les debemos agregar 5 ceros para comparar
        int tax;
        if(total.compareTo(new BigInteger("10").pow(7+5)) <= 0)
            tax = 0;
        else if(total.compareTo(new BigInteger("10").pow(10+5)) <= 0)
            tax = 10;
        else if(total.compareTo(new BigInteger("10").pow(13+5)) <= 0)
            tax = 20;
        else if(total.compareTo(new BigInteger("10").pow(16+5)) <= 0)
            tax = 30;
        else
            tax = 40;

    
        //aqui multiplicamos por tax pero nos falta dividir por 100
        //aqui ya dividimos por 10, por lo que nos falta dividir "pagar" por 10^5 que llevamos de 
        //inicio y 10 que nos quedan de aqui (en total 10^6)
        BigInteger pagar = total.multiply(new BigInteger(tax/10+""));

        //aqui manejamos las reglas de tax y dividimos por el 10 que nos faltaba del porcentaje
        //ahora solo falta dividir por 10^5
        int comp = pagar.mod(BigInteger.TEN).compareTo(new BigInteger("5"));
        pagar = pagar.divide(BigInteger.TEN);
        if( comp > 0)
            pagar = pagar.add(BigInteger.ONE);
        else if(comp == 0 && pagar.mod(new BigInteger("2")).equals(BigInteger.ONE))
            pagar = pagar.add(BigInteger.ONE);  

        //dividimos por 10^5 tanto pagar como total
        BigDecimal totalD = new BigDecimal(total);
        totalD = totalD.divide(BigDecimal.TEN.pow(5));
        System.out.printf("%.5f", totalD);
        
        //imprimimos el porcentaje
        System.out.print(" "+tax+"% ");

        //imprimimos el total de taxes
        aux = new BigDecimal(pagar);
        aux = aux.divide(BigDecimal.TEN.pow(5));
        System.out.printf("%.5f", aux);
        System.out.println("");
        
    }
    
}

