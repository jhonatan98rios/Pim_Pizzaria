const gulp = require('gulp');
const exec = require('child_process').exec;

const builds = [
    "sudo gcc ./index.c -o ./index",
    "sudo gcc ./source/menu.c -o ./source/menu",
    "sudo gcc ./source/produtos/MenuProduto.c -o ./source/produtos/MenuProduto",
    "sudo gcc ./source/produtos/CadastrarProduto.c -o ./source/produtos/CadastrarProduto",
    "sudo gcc ./source/produtos/VizualizarProduto.c -o ./source/produtos/VizualizarProduto",
    "sudo gcc ./source/promocoes/VizualizarPromocoes.c -o ./source/promocoes/VizualizarPromocoes"
];

builds.forEach((index)=>{
    gulp.task('default', async function(){
        console.log(index);
        exec(index, function(error, stdout, stderr){
            console.log(stdout);
            console.log(stderr);
        });
    });
});


/* gulp.task('default', async function(){
    console.log(builds[5]);
    exec(builds[5], function(error, stdout, stderr){
        console.log(stdout);
        console.log(stderr);
    });
}); */
