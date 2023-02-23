% Gráfica de una función f de R^2 en R. El dominio de graficación
% es un círculo de radio r y coordenads del centro centrox, centroy.
% ENTRADA: f,r,centrox,centroy, NumPuntosRadio,NumPuntosAngulo
%  f = función que se  grafica
%  r= radio del círculo en el dominio de graficación
%  centrox= abscisa del centro del círculo de graficación
%  centroy= ordenada del centro del círculo de graficación
%  NumPuntosRadio= Número de puntos usados para discretizar la variable r
%  NumPuntosAngulo= Número de puntos usados para discretizar el ángulo en
%                   [0,2*pi] en coordenadas polares.
% 
% NOTA: La función f se especifica en la forma @(x,y)Definición
% Por ejemplo si la funcón está dada por x^2-xy*exp(-x^2+y)
% f se especifica como @(x,y) x.^2-x.*y.*exp(-x.^2+y)
% Multiplicaciones, divisiones y potencias se especifican como:
%   Multiplicación:  .*  
%   División:   ./   
%   Potencias: .^  
%  
%  Si es multipicación o división por una contante el punto puede omitirse.  
% Uso:  SuperficieCirculo(f,r,centrox,centroy, NumPuntosRadio,NumPuntosAngulo)
% Ejemplo: Graficar f(x,y)=(1-x^2-y^2)exp(-x^2-y^2) en un círculo de 
% radio 2 centrado en (0,0) usando 50 puntos para el radio y 60 puntos para
% el ángulo:
% En la línea de comando escribir 
%  SuperficieCirculo(@(x,y) (1-x.^2-y.^2).*exp(-x.^2-y.^2),2,0,0,50,60)
% Si se desea ver la gráfica sin mallado, escribir:
% shading interp
% Si se desea cambiar la paleta de colores, usar alguna de:
% colormap gray, colormap copper, colormap jet, colormap pink, etc (ver
% help colormap)

function []=SuperficieCirculo(f,r,centrox,centroy, NumPuntosRadio,NumPuntosAngulo)

r=linspace(0,r,NumPuntosRadio);
t=linspace(0,2*pi,NumPuntosAngulo);
[r,t]=meshgrid(r,t);
x=r.*cos(t); y=r.*sin(t);
x=x+centrox; y=y+centroy;
z=ones(NumPuntosRadio,NumPuntosRadio);
z=f(x,y).*ones(NumPuntosRadio,NumPuntosRadio);
surf(x,y,z)
xlabel('eje x'); ylabel('eje y'); zlabel('eje z');
