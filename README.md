To compile file:

in Commando Line in project directory:

qmake -o Makefile QtApp.pro

then:

make

then:

./myCommunity


--------------------------------------------------

<h3>Um Datein in GitLab zu pushen:</h3>

Immer zuerst pullen:<br>

<code>git pull</code>

Status überprüfen:

git status

Gewünschte Datein hinzufügen:

all Files:

git add .

oder bestimmtes file:

git add test.pdf

Überprüfen ob die gewünschten Datein bereit zum pushen:<br>
git status

ein kleine message über Aufgabe hinterlassen:

git commit -m "message"

Endlich: pushen :)

git push
