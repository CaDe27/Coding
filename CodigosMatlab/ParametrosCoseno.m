%Carlos Delgado 181866
%Septiembre 17, 2018
%Introducci�n a la Ingenier�a

%Gr�fica de la funci�n coseno con distintas amplitudes
x=-2*pi:0.001:2*pi;
u=cos(x);
y=0.5*cos(x);
v=3*cos(x);
z=zeros(size(x));
plot (x,u, 'r', x,y,'k', x, v, 'g', x,z, 'k');
grid on;

xlabel("�ngulo en radianes");
title("Gr�fica de la funci�n coseno con distintas amplitudes");
legend("Amplitud=1","Amplitud=0.5", "Amplitud=3");
axis([(-2)*pi 2*pi (-3) 3]);

%Gr�fica de la funci�n coseno con distintos periodos
x=0:0.001:1;
u=cos(2*pi*x);
y=cos(0.1*2*pi*x);
w=cos(0.5*2*pi*x);
v=cos(2*2*pi*x);
z=zeros(size(x));
plot (x,u, 'r', x,y,'k', x,w,'b', x, v, 'g', x,z, 'k');
grid on;
 
xlabel("Periodos");
title("Gr�fica de la funci�n coseno con distintos periodos");
legend("Periodo=1","Periodo=0.1", "Periodo=0.5","Periodo=2");

%Gr�fica de la funci�n coseno con distintas fases
x=-2*pi:0.001:2*pi;
u=cos(x);
y=cos(x+ pi/4);
w=cos(x + pi/2);
v=cos(x+ 0.738*pi);
z=zeros(size(x));
plot (x,u, 'r', x,y,'k', x,w,'b', x, v, 'g', x,z, 'k');
grid on;

xlabel("�ngulo en Radianes");
title("Gr�fica de la funci�n coseno con distintas fases");
legend("Fase=0","Fase=pi/4", "Fase=pi/2", "Fase=0.738*pi");
axis([(-2)*pi 2*pi (-1) 1]);
