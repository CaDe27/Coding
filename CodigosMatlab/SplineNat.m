function [m] = SplineNat(x,y)
%INPUT:  
%   x = vector con los valores correspondientes al eje x
%   y = vector con los valores correspondientes al eje y

%OUTPUT
%   m = vector que tendra los valores de las pendientes para hacer el
%   spline

%El spline natural añade dos ecuaciones al sistema de ecuaciones, para que
%la matriz sea invertible. Ademas,como sera estrictamente diagonal dominante, se podra usar Cholesky para
%resolver eficientemente el sistema de ecuaciones para obtener las
%pendientes de cada punto

n = length(x);  %cantidad de puntos que tenemos
h = zeros(n-1,1); %sera el vector que guarde la longitud entre un punto y otro en el eje x. Evidentemente, siempre es uno menos que la cantidad de puntos
yprima = zeros(n-1,1); %sera el vector que guarde los datos de la diferencia entre los valores de y,dividida por la longitud del intervalo correspondiente
fi = zeros(n); %sera el vector que guarda los valores constantes para resolver el sistema Am = fi
A = zeros(n,n);  %sera la matriz utilizada para resolver Am = fi, donde m sera el valor del output, mientras que fi es el vector descrito anteriormente

for i=1:n-1
    h(i) = x(i+1)-x(i); %Asignamos entrada por entrada el valor de h
    yprima(i) = (y(i+1)-y(i))/h(i); %Asignamos entrada por entrada los valores de y ptimas (descritas arriba)
end
%Necesitabamos obtener el vector h para poder componer la matriz A
%iterativamente. El paso siguiente sera formar la matriz A
for i=1:n
    if i<n-1
        A(i+1,i)=h(i+1); %Para los elementos abajo de la diagonal
    end
    if i>2
        A(i-1,i) = h(i-2); %Para los  elementos arriba de la diagonal
    end
    if i>1
        if i<n
        A(i,i) = 2*(h(i-1)+h(i)); % solo faltara la entrada A(n,n), que se ajustara posteriormente
        end
    end
end
%Solo faltan corregir un par de cosas en la Matriz A para que quede
%completa
A(1,1) = 2;
A(1,2) = 1; 
A(n,n-1) = 1; 
A(n,n)=2; %Ahora si queda corregida la matriz y esta completa

%Ahora, tenemos que crear la matriz de resultados fi
for i=2:n-1
    fi(i) = 3*yprima(i)*h(i-1)+3*yprima(i-1)*h(i); %de esta manera quedan definidas todas las entradas menos la primera y la ultima   
end
fi(1) = 3*yprima(1);
fi(n) = 3*yprima(n-1); 

%Finalmente tenemos lo que necesitamos en el sistema Am = fi
%Como se menciono antes, al ser matriz estrictamente diagonal dominante,
%podemos usar Cholesky para resolver el sistema.

m = ResuelveCholesky(A,fi);
end

