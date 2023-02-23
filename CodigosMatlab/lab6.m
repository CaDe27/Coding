%{
%linspace genera un vector de 100 entradas con lim inferior
% x1 y superior x2  y uniformemente espaciado
% es decir el k-esimo numero es x1 - (x2-x1)*k/(n-1)

% si le das 3 parametros, y el tercero es n ya no da 100 
% entradas, sino n

x = linspace(1,10,20);
y = linspace(1,20,20);
%cada que uses figure, creas una nueva ventana de grafica
%hold on sirve apra que en la misma grafica traslapes otras
%hold off para ya no traslapar y borrar lo anterior antes
%         de graficar otra cosa

figure
plot(x,y)
figure
plot(x,y,'-', 'Linewidth',2);
hold on
plot (x,y,'o');
hold off

%6
x = pi*linspace(0, 2,5);
x = x';
m = matrizBaseNewton(x)

%7
y = [0;1;0;-1;0];
c = ResuelveTI(m,y);
%8
%y si da los y que deberia
evaluaPoliBaseNewton(c, x, x)

%9
x2 = linspace(0,2*pi)';
y2 = evaluaPoliBaseNewton(c,x,x2);

%10
figure 
plot(x2, y2)
hold on
plot(x,y, 'o')
hold off

%11
x2 = linspace(-10,10)';
y2 = evaluaPoliBaseNewton(c,x,x2);
figure 
plot(x2, y2)
hold on
plot(x,y, 'o')
hold off
%}
%14
x = linspace(-1,1)';
plot(x, pol_Chebyshev(x,0));
hold on
for i = 1:1
    plot(x, pol_Chebyshev(x,6));
    
end
legend('chev1', 'chev2')
hold off