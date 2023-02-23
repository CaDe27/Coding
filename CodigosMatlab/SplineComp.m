function [m] = SplineComp(a,b,x,y)
%INPUT:  
%   a = valor de m1, es decir, la primera pendiente
%   b = valor de mn, es decir de la ultima pendiente. Se determinan de esta
%   manera para que el sistema de ecuaciones a resolver tenga solucion
%   unica
%   x = vector con los valores correspondientes al eje x
%   y = vector con los valores correspondientes al eje y

%OUTPUT
%   m = vector que tendra los valores de las pendientes para hacer el
%   spline

%El spline completo determina arbitrariamente la primera pendiente y la
%ultima pendiente para que el sistema de ecuaciones tenga solucion unica. 

n = length(x);
h = zeros(n-1,1); %sera el vector que guarde la longitud entre un punto y otro en el eje x
yprima = zeros(n-1,1); %sera el vector que guarde los datos de la diferencia entre los valores de y,dividida por la longitud del intervalo correspondiente
fi = zeros(n-2); %sera el vector que guarda los valores constantes para resolver el sistema Am = fi
A = zeros(n-2,n-2);  %sera la matriz utilizada para resolver Am = fi, donde m sera el valor del output, mientras que fi es el vector descrito anteriormente
for i=1:n-1
    h(i) = x(i+1)-x(i); %Asignamos entrada por entrada el valor de h
    yprima(i) = (y(i+1)-y(i))/h(i); %Asignamos entrada por entrada los valores de y ptimas (descritas arriba)  
end
%Necesitabamos obtener el vector h para poder componer la matriz A
%iterativamente. 
for i = 1:n-2
    A(i,i) = 2*(h(i)+h(i+1));
    if 1<i
        A(i-1,i)=h(i-1);
    end
    if i<n-2
        A(i+1,i) = h(i+2);
    end
end

for i=2:n-1
    fi(i-1) = 3*yprima(i)*h(i-1)+ 3*yprima(i-1)*h(i); %De esta manera recorremos los n-2 elementos de la matriz
end
fi(1) = fi(1) -h(1)*a; %es necesario para que se ajuste el spline completo, pues la primera derivada sera una constante para nosotros
f(n-2)= fi(n-2) -h(n-2)*b;  %es necesario para que se ajuste el spline completo, pues la ultima derivada sera una constante para nosotros

%Ahora, tenemos finalmente completo nuestro sistema Am = fi. Debemos de
%Notar que A es una matriz estrictamente diagonal dominante. Por lo tanto,
%podemos usar Cholesky para resolver el sistema. 

m = ResuelveCholesky(A,fi);
end

