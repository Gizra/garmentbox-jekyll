#!/bin/bash

sudo rm -rf www/

bash scripts/build

cd www

cp sites/default/default.settings.php sites/default/settings.php
mkdir sites/default/files

drush si -y gbmarket --account-pass=admin --db-url=mysql://root@localhost/gbmarket --db-su=root -v

drush mi --all --user=1

chmod -R 777 sites/default/files
