<h3>To compile file under Linux/Mac:</h3>

in Commando Line in project directory:<br>

<code>qmake -o Makefile QtApp.pro</code>

then:<br>
<code>make</code>

then:<br>
<code>./myCommunity</code>

---------------------------------------------------

<h3> To allow Test compilation, please do the following steps: </h3>

<h4>In QtCreator:</h4>
1. Choose "Projects" on the side bar of the QtCreator Window.<br>
2. Under "Build Settings" click on "Add" and choose "Clone Selected".<br>
3. You will be asked to give a name. Call it "Test".<br>
4. Under "Build Steps" show more details about "qmake".<br>
5. In "Additional Arguments" write down the following:
      <code>CONFIG += "test"</code><br>

<h4>To run the Project in "Test Mode":</h4>
1. Choose the Build mood "Test" on the side bar bottom over the Run Button.<br>
2. Click Run.<br>

Results listed in "Applications Output".

----------------------------------------------------
