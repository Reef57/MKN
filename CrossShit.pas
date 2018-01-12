program CrossShit;
type
  point = record
    x, y, x1, y1: integer;
  end;

function skal(x1, y1, x2, y2, x3, y3: integer):integer;
begin
     result := (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
end;

function cross(a, b:point):boolean;
var
  i: integer;
begin
     i := 0;
     if skal(a.x, a.y, a.x1, a.y1, b.x1, b.y1)*skal(a.x, a.y, a.x1, a.y1, b.x, b.y) < 0 then inc(i);
     if skal(b.x, b.y, b.x1, b.y1, a.x1, a.y1)*skal(b.x, b.y, b.x1, b.y1, a.x, a.y) < 0 then inc(i);
     if (skal(a.x, a.y, a.x1, a.y1, b.x, b.y) = 0) and (((a.x-b.x)*(a.x1-b.x)+(a.y-b.y)*(a.y1-b.y)) <= 0) then i := 2;
     if (skal(a.x, a.y, a.x1, a.y1, b.x1, b.y1) = 0) and (((a.x-b.x1)*(a.x1-b.x1)+(a.y-b.y1)*(a.y1-b.y1)) <= 0) then i := 2;

     if i = 2 then result := true else result := false;
end;

var
  v: array of point;
  n, i, k, xt, yt: integer;
begin
  write('Input number of vector: ');
  readln(n);
  setlength(v, n);
  for i := 0 to n-1 do
  begin
      writeln('Input point of vector: ');
      read(v[i].x);
      read(v[i].y);
      read(v[i].x1);
      read(v[i].y1);
      if v[i].x*v[i].y > v[i].x1*v[i].x then
      begin
        xt := v[i].x;
        yt := v[i].y;
        v[i].x := v[i].x1;
        v[i].y := v[i].y1;
        v[i].x1 := xt;
        v[i].y1 := yt;
      end;
  end;

  for i := 0 to n-2 do
      for k := i+1 to n-1 do
      begin
           if cross(v[i], v[k]) then
           begin
             writeln(i, ' ', k, ' cross');
           end;
      end;
  readln(k);
end.

