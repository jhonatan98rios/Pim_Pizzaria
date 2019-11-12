const gulp = require('gulp');
const exec = require('child_process').exec;

const builds = [
    "sudo gcc ./index.c -o ./index",
    "sudo gcc ./source/menu.c -o dist/menu",

    "sudo gcc ./source/clientes/MenuClientes.c -o dist/clientes/MenuClientes",
    "sudo gcc ./source/clientes/CadastrarClientes.c -o dist/clientes/CadastrarClientes",
    "sudo gcc ./source/clientes/VisualizarClientes.c -o dist/clientes/VisualizarClientes",
    "sudo gcc ./source/clientes/EditarClientes.c -o dist/clientes/EditarClientes",

    "sudo gcc ./source/estoque/MenuEstoque.c -o dist/estoque/MenuEstoque",
    "sudo gcc ./source/estoque/CadastrarEstoque.c -o dist/estoque/CadastrarEstoque",
    "sudo gcc ./source/estoque/VisualizarEstoque.c -o dist/estoque/VisualizarEstoque",
    "sudo gcc ./source/estoque/EditarEstoque.c -o dist/estoque/EditarEstoque",

    "sudo gcc ./source/login/Login.c -o dist/login/Login",

    "sudo gcc ./source/pedidos/MenuPedidos.c -o dist/pedidos/MenuPedidos",
    "sudo gcc ./source/pedidos/CadastrarPedido.c -o dist/pedidos/CadastrarPedido",

    "sudo gcc ./source/produtos/MenuProdutos.c -o dist/produtos/MenuProdutos",
    "sudo gcc ./source/produtos/CadastrarProduto.c -o dist/produtos/CadastrarProduto",
    "sudo gcc ./source/produtos/VisualizarProduto.c -o dist/produtos/VisualizarProduto",

    "sudo gcc ./source/reclamacoes/MenuReclamacoes.c -o dist/reclamacoes/MenuReclamacoes",
    "sudo gcc ./source/reclamacoes/CadastrarReclamacoes.c -o dist/reclamacoes/CadastrarReclamacoes",
    "sudo gcc ./source/reclamacoes/VisualizarReclamacao.c -o dist/reclamacoes/VisualizarReclamacao",

    "sudo gcc ./source/funcionarios/MenuFuncionarios.c -o dist/funcionarios/MenuFuncionarios",
    "sudo gcc ./source/funcionarios/CadastrarFuncionario.c -o dist/funcionarios/CadastrarFuncionario",
    "sudo gcc ./source/funcionarios/VisualizarFuncionario.c -o dist/funcionarios/VisualizarFuncionario",
    "sudo gcc ./source/funcionarios/ExcluirFuncionario.c -o dist/funcionarios/ExcluirFuncionario",

    "sudo gcc ./source/relatorios/MenuRelatorios.c -o dist/relatorios/MenuRelatorios",
    "sudo gcc ./source/relatorios/VisualizarRelatorios.c -o dist/relatorios/VisualizarRelatorios"
];


gulp.task('default', async function(){
    builds.forEach((build)=>{
        exec(build, function(stdout, stderr){
            /* console.log(stdout);
            console.log(stderr); */
        });
    });
});

