%laboratorio 9

A = [1,0,-1,2; 2,1,0,0; 0, 2, -8, 4; 1,1,-2,0];
b = [1,2,3,4]';

%mandamos a resolver el sistema mediante factorización QR y comprobamos
%que x sea solución
x = ResuelveQR(A, b);
if( abs(A*x - b) < 1e-8)
    disp('x sí es solución')
else
    disp('x no es solución ')
end

%Regla del trapecio

disp('con 1 intervalo')
x = IntegralTrapecio('sin', 0, pi, 1)

disp('con 5 intervalos')
x = IntegralTrapecio('sin', 0, pi, 5)

disp('con la verdadera integral (-cos(x))')
x = -cos(pi) + cos(0)





