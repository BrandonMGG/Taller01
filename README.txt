Para correr Taylor:
Ejecutar en la terminal lo siguiente:
	
	gcc -fopenmp -o taylor  taylor.c        (Necesario)
	./taylor 			    ||	(si quiere ver el output)
	.\run_taylor.bat		    ||	(Necesario  || para generar txt files)
	python plotter.py		    ||  (Mostrar Grafica)

Para correr Daxpy:
	gcc -fopenmp -o daxpy daxpy.c  
	./daxpy
	.\run_daxpy.bat
	python plotdaxpy.py
