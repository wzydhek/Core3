cd ..\MMOCoreORB\
java -XX:TieredStopAtLevel=1 -client -Xmx128M -cp utils\engine3\MMOEngine\lib\idlc.jar org.sr.idlc.compiler.Compiler -outdir autogen -cp utils\engine3\MMOEngine\src -sd src anyadEclipse
