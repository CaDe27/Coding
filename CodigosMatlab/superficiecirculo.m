% Gr�fica de una funci�n f de R^2 en R. El dominio de graficaci�n
% es un c�rculo de radio r y coordenads del centro centrox, centroy.
% ENTRADA: f,r,centrox,centroy, NumPuntosRadio,NumPuntosAngulo
%  f = funci�n que se  grafica
%  r= radio del c�rculo en el dominio de graficaci�n
%  centrox= abscisa del centro del c�rculo de graficaci�n
%  centroy= ordenada del centro del c�rculo de graficaci�n
%  NumPuntosRadio= N�mero de puntos usados para discretizar la variable r
%  NumPuntosAngulo= N�mero de puntos usados para discretizar el �ngulo en
%                   [0,2*pi] en coordenadas polares.
% 
% NOTA: La funci�n f se especifica en la forma @(x,y)Definici�n
% Por ejemplo si la func�n est� dada por x^2-xy*exp(-x^2+y)
% f se especifica como @(x,y) x.^2-x.*y.*exp(-x.^2+y)
% Multiplicaciones, divisiones y potencias se especifican como:
%   Multiplicaci�n:  .*  
%   Divisi�n:   ./   
%   Potencias: .^  
%  
%  Si es multipicaci�n o divisi�n por una contante el punto puede omitirse.  
% Uso:  SuperficieCirculo(f,r,centrox,centroy, NumPuntosRadio,NumPuntosAngulo)
% Ejemplo: Graficar f(x,y)=(1-x^2-y^2)exp(-x^2-y^2) en un c�rculo de 
% radio 2 centrado en (0,0) usando 50 puntos para el radio y 60 puntos para
% el �ngulo:
% En la l�nea de comando escribir 
%  SuperficieCirculo(@(x,y) (1-x.^2-y.^2).*exp(-x.^2-y.^2),2,0,0,50,60)
% Si se desea ver la gr�fica sin mallado, escribir:
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
