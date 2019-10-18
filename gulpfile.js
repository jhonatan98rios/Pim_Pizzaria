const gulp = require('gulp');
const exec = require('child_process').exec;

const builds = [
    "sudo gcc ./index.c -o ./index",
    "sudo gcc ./source/menu.c -o ./source/menu",
    "sudo gcc ./source/produtos/MenuProduto.c -o ./source/produtos/MenuProduto",
    "sudo gcc ./source/produtos/CadastrarProduto.c -o ./source/produtos/CadastrarProduto",
    "sudo gcc ./source/produtos/VizualizarProduto.c -o ./source/produtos/VizualizarProduto",
    "sudo gcc ./source/pedidos/MenuPedidos.c -o ./source/pedidos/MenuPedidos",
    "sudo gcc ./source/pedidos/CadastrarPedido.c -o ./source/produtos/CadastrarPedido",
];

for(let i = 0; i < 4; i++){
    gulp.task('default', async function(){
        exec(builds[i], function(error, stdout, stderr){
            console.log(stdout);
            console.log(stderr);
        });
    });
};
