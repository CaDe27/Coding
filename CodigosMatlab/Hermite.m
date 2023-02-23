function [M] = Hermite(a,b,m)
%Input:
%   a = matriz de puntos en el eje x (2x2)
% b = matriz de puntos en el eje y. En realidad son las x evaluadas en el
% polinomio
% m = derivada de la función evaluada en x

%Output: 
% un vector d 4x1 que tenga los coeficientes Ci con i=1,...,4
M=zeros(4,1);
h = a(2)-a(1);
c = (b(2)-b(1))/h; 
M(1) = b(1);
M(2) = m(1);
M(3) = (c-m(1))/h;
M(4) = (m(1)+m(2)-2*(c))/(h^2);
 
end

