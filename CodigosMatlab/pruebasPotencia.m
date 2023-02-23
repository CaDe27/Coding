close all; clear all; clc;
%pruebas potencia
%a = [1,2,3]';
%A = diag(a);

%[l0, v0] = MetodoPotencia(A, a);
%[l1, v1] = potenciaInversa(A, 0, a);

%si regresa nan, rho es eigenvalor
%[l2,v2] = potenciaInversa(A, (l0+l1)/2 , a);

A = [20 1 -4 3 5; 0 -13 1 3 13; 12 -4 5 5 9; 6 7 8 -9 10; -1 1 1 1 -1];
a = [1,2,3,4,5]';

[l0, v0] = MetodoPotencia(A,a)  %l0 = 17.4603
disp('deben ser todos iguales');
(A*v0)./v0

[l1, v1] = potenciaInversa(A, 0, a) %l1 = 1.0450
disp('deben ser todos iguales');
(A*v1)./v1

%uso "metodo de la biseccion" para rastrear mas eigenvalores
[l2,v2] = potenciaInversa(A,  (l0+l1)/2 , a) %l2 = 10.0346
disp('deben ser todos iguales');
(A*v2)./v2

%busco entre l1 y l2
%no hay entre ellos con este vector, porque busco en la mitad +1 y en mitad-1
% y se van a l1 y l2 de nuevo
[l3,v3] = potenciaInversa(A,  (l1+l2)/2 +1 , a) %l3 = 
disp('deben ser todos iguales');
(A*v3)./v3

%busco entre l0 y l2
%no hay entre ellos con este vector, porque busco en la mitad +1 y en mitad-1
% y se van a l0 y l2 de nuevo
[l3,v3] = potenciaInversa(A,  (l0+l2)/2 -1 , a); %l3 = 
disp('deben ser todos iguales')
(A*v3)./v3

disp('busqueda en negativos')
%ahora busco en los negativos de mi rango [menor,mayor] [ -17  -1]
%ya que solo he buscado entre los rangos positivos

[l3,v3] = potenciaInversa(A, -(l1+l2)/2 , a) %l3 = -9.7223
disp('deben ser todos iguales');
(A*v3)./v3

%ahora busco en rango [-1 , -9.7223]
[l4,v4] = potenciaInversa(A, (-l1+l3)/2 , a) %l4 =
disp('deben ser todos iguales');
(A*v4)./v4

%vuelve a dar -9.7223, asi que busco entre [-17, -9]
[l4,v4] = potenciaInversa(A, (-l0+l3)/2 , a) %l4 = -16.817
disp('deben ser todos iguales');
(A*v4)./v4

%hay variaciones significativas en los decimales asi que ahora lo busco mas
%cerca de donde ya se que esta
[l4,v4] = potenciaInversa(A, -16.81 , a) %l4 = -16.8176
disp('deben ser todos iguales');
(A*v4)./v4

disp('eigenvalores y eigenpares')
[l0, l1, l2, l3, l4]
[v0,v1,v2,v3,v4]



