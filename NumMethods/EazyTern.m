A = [10 2 -1 5; -2 -6 -1 24.42 ; 1 -3 12 36]
n = 3;
x = zeros(1, n);
x1 = zeros(1, n);
e = 0.001;
for i = 1:1:n
    for k = 1:1:n+1
       if i ~= k
        A(i, k) = A(i, k)/A(i, i);
       end 
    end
    A(i, i) = 0;
end

for k = 1:1:n
  xt = 0;
  for j = 1:1:n
    xt = xt + A(k, j)*x(1, j); 
  end
  x1(1, k) = A(k, n+1) - xt; 
end 

while e < norm((x1 - x), 1)
   x = x1; 
   for k = 1:1:n
      xt = 0;
      for j = 1:1:n
         xt = xt + A(k, j)*x(1, j); 
      end
      x1(1, k) = A(k, n+1) - xt; 
   end  
end
x