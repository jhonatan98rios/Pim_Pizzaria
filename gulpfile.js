const gulp = require('gulp');
const exec = require('child_process').exec;

const builds = [
    "sudo gcc ./index.c -o ./index",
    "sudo gcc ./source/menu.c -o dist/menu",
    "sudo gcc ./source/produtos/MenuProdutos.c -o dist/produtos/MenuProdutos",
    "sudo gcc ./source/produtos/CadastrarProduto.c -o dist/produtos/CadastrarProduto",
    "sudo gcc ./source/produtos/VisualizarProduto.c -o dist/produtos/VisualizarProduto",
];


gulp.task('default', async function(){
    builds.forEach((build)=>{
        exec(build, function(stdout, stderr){
            console.log(stdout);
            console.log(stderr);
        });
    });
});

/* for(let i = 0; i < 4; i++){
    gulp.task('default', async function(){
        exec(builds[i], function(error, stdout, stderr){
            console.log(stdout);
            console.log(stderr);
        });
    });
}; */
