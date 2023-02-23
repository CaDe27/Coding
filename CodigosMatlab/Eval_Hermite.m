function [x] = Eval_Hermite(w,a,b,m)
%Input: 
% w = punto en el que será evaluado el polinomio de Hermite
% a,b y m son requeridos para poder utilizar la fncion Hermite y obtener la
% matriz de constantes. a son los puntos en el eje x, b = f(a), m =
% pendientes

%Output
%x = Polinomio de Hermite evaluado en el punto w

M=Hermite(a,b,m);
x = M(1)+M(2)*(w-a(1))+M(3)*((w-a(1))^2)+M(4)*((w-a(1))^2)*(w-a(2));
end

