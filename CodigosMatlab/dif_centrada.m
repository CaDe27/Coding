function[dc] = dif_centrada(fname, a, h)
    %{
    Nombre: Carlos Delgado
    Programa que regresa la aproximación a la derivada de f en 
        mediante el método de la diferencia centrada
        es decir usamos  (f(a+h) - f(a-h))/(2h)
        IN:
           fname - nombre de la funcion f
           a     - punto donde se deriva
           h     - diferencia utilizada
        OUT:
           df    - la derivada aproximada con este metodo
    %}
    
    fah2 = feval(fname, a+h);
    fah1 = feval(fname, a-h);
    dc = (fah2 - fah1)/(2*h);
   
end