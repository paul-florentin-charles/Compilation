
Pour construire le projet :
make

Pour lancer les tests et mettre les résultats dans les .ll et .txt :
bash run_tests.sh [-v] [-f FILE]

/!\ Ne pas mettre le .c dans FILE, par exemple, pour afficher test/test_func.c écrire :
bash run_tests.sh -v -f test/test_func

pour compiler prog.c :
sh compil.sh prog


Notes complémentaires à l'attention du correcteur :
- Dans le test 18, nous avons retiré le ";" dans les paramètres de la fonction qui semble être une faute de frappe.
