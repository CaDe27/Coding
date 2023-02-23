%2. eps recuerdo que es la distancia entre 1 y la proximo numero que aun toma
%como 1
%un numero 
eps

% 3. lo que pasa es que b y a los considera como el mismo numero
%c y a no, pues la distancia ya es mayor a eps
a = 2; b = 2+eps; c = 2+3*eps;
b-a
c-a

%4. la solucion que puede tener problemas es donde  b tiene el mismo signo
% que +-sqrt(b**2 - 4ac), pues puede ser que este tomando al cero como una
% solucion

%lo que podemos hacer es multiplicar por el conjungado, de modo que
%eliminamos la eliminacion fatal (cuando 4ac suficientemente pequeno
%respecto a b^2)

% en el siguiente ejemplo la primera da x1 = 0, mientras que en la segunda
% si da una mejor aproximacion de x1
[x1,x2] = cuadraticaProblematica(0.00000001, 10, 0.000000000000001)
[x1,x2] = cuadratica(0.00000001, 10, 0.000000000000001)

%5. 6. y 7.
A = 0.5*eye(10);
b = [1;2;3;4;5;6;7;8;9;10];
ResuelveTI(A, b)
ResuelveTS(A,b)

%triangular superior