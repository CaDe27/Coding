% Autores: 
%Ricardo Parente  180873
% Mariano Gonzalez 181143
% Emilio Mena   176115
% Carlos Delgado 181866

%Fecha: 15 de mayo de 2020

clear all 
close all
clc

%Para empezar, se tienen que leer los datos de los puntos del
%electrocardiograma. Son 60 puntos especificamente. Por default la
%computadora descargo los datos a excel. Para poder utilizarlos en matlab
%se utilizara la herramienta xlsread
ECG = xlsread('DatosECG.xls');   %ECG será nuestro eje y 

%por otro lado, estos 60 datos estan igualmente espaciados en un segundo.
%Es decir, dividiremos 1000 milisegundos (1 segundo) en 60 partes iguales
%utilizando la herramienta linspace. 
x = linspace(0,1000,60);

%figure 
%plot(x,ECG)

%Para graficar los puntos como curva suave, usaro¡emos interpolacion de
%hermite y splines.

%Utilizando la tecnica de SPLINE COMPLETO, obtenderemos los valores de
%todas las pendientes en un vector m. Para eso, usaremos la funcion creada
%SplineComp
%Los valores que le daremos a la primera pendiente y la ultima son 1 y 1
%respectivamente
m1 = SplineComp(1,1,x,ECG);  %Es el vector de 58 elementos. 

%Crearemos un nuevo vector que contenga los 60 valores
m2=zeros(60,1);
m2(1) = -3; 
m2(2:59,1)=m1; 
m2(60) = 0;

% Se puede realizar una interpolacion de Hermite por cada dos puntos. Por
% lo tanto, en total tendremos 59 polinomios de Hermite. 

y = []; %Lo pondremos como el conjunto vacio para empezar a acumular los puntos de y
xacum = []; %Lo pondremos como el conjunto vacio para empezar a acumular los puntos de x

for i=1:59
    x1 = linspace(x(i),x(i+1));    %Para poder graficar en cada intervalo de puntos
    n = length(x1);
    y1 = zeros(n,1);               %Es donde se guardaran los valores del polinomio de Hermite evaluado en cada uno de los 59 intervalos
    for j=1:n
        y1(j) = Eval_Hermite(x1(j),x(i:i+1),ECG(i:i+1),m2(i:i+1));
    end
    y = [y;y1];           %Aqui guardaremos los valores de todas las y para poder graficar
    xacum = [xacum x1];    %Aqui guardaremos los valores de todas las x para poder graficar 
    
end

%Grafica Spline Completo
figure('Color',[0.9 0.9 0.9]);set(gca,'color',[0 0 0])
hold on
plot(xacum,y,'w')  %Aqui se puede ver claramente que el ECG es continuo a partir del uso del Spline Completo y la interpolacion de Hermite
hold on 
grid on
ax = gca;
ax.GridColor = [1 1 1];
hold off



%Veamos ahora el caso con SPLINE NATURAL. Lo que hacemos en este metodo, a
%diferencia del otro es añadir 2 ecuaciones al sistema de ecuaciones, para
%que que la matriz pueda ser invertible y tenga solucion unica. Ademas,
%como sera estrictamente diagonal dominante, se podra usar Cholesky para
%resolver eficientemente el sistema de ecuaciones para obtener las
%pendientes de cada punto, para posteriormente utilizar interpolacion de
%Hermite para graficar la funcion continua. 

mm1 = SplineNat(x,ECG); %Se obtienen directamente las 60 derivadas sin necesidad de ajustar

% Se puede realizar una interpolacion de Hermite por cada dos puntos. Por
% lo tanto, en total tendremos 59 polinomios de Hermite. 

yy = []; %Lo pondremos como el conjunto vacio para empezar a acumular los puntos de y usando SPLINE NATURAL
xxacum = []; %Lo pondremos como el conjunto vacio para empezar a acumular los puntos de x usando SPLINE NATURAL

for i=1:59
    x11 = linspace(x(i),x(i+1));    %Para poder graficar en cada intervalo de puntos
    n = length(x11);
    y11 = zeros(n,1);               %Es donde se guardaran los valores del polinomio de Hermite evaluado en cada uno de los 59 intervalos
    for j=1:n
        y11(j) = Eval_Hermite(x11(j),x(i:i+1),ECG(i:i+1),mm1(i:i+1));
    end
    yy = [yy;y11];           %Aqui guardaremos los valores de todas las y para poder graficar
    xxacum = [xxacum x11];    %Aqui guardaremos los valores de todas las x para poder graficar 
end

%Grafica Spline Natural
figure('Color',[0.9 0.9 0.9]);set(gca,'color',[0 0 0])
hold on
plot(xxacum,yy,'w') 
hold on 
grid on
ax = gca;
ax.GridColor = [1 1 1];
hold off