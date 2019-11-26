const gulp = require('gulp');
const exec = require('child_process').exec;

const builds = [
    "gcc ./index.c -o ./index",
    "gcc ./source/menu.c -o dist/menu",

    "gcc ./source/clientes/MenuClientes.c -o dist/clientes/MenuClientes",
    "gcc ./source/clientes/CadastrarClientes.c -o dist/clientes/CadastrarClientes",
    "gcc ./source/clientes/VisualizarClientes.c -o dist/clientes/VisualizarClientes",
    "gcc ./source/clientes/EditarClientes.c -o dist/clientes/EditarClientes",

    "gcc ./source/estoque/MenuEstoque.c -o dist/estoque/MenuEstoque",
    "gcc ./source/estoque/CadastrarEstoque.c -o dist/estoque/CadastrarEstoque",
    "gcc ./source/estoque/VisualizarEstoque.c -o dist/estoque/VisualizarEstoque",
    "gcc ./source/estoque/EditarEstoque.c -o dist/estoque/EditarEstoque",

    "gcc ./source/login/Login.c -o dist/login/Login",

    "gcc ./source/pedidos/MenuPedidos.c -o dist/pedidos/MenuPedidos",
    "gcc ./source/pedidos/CadastrarPedido.c -o dist/pedidos/CadastrarPedido",

    "gcc ./source/produtos/MenuProdutos.c -o dist/produtos/MenuProdutos",
    "gcc ./source/produtos/CadastrarProduto.c -o dist/produtos/CadastrarProduto",
    "gcc ./source/produtos/VisualizarProduto.c -o dist/produtos/VisualizarProduto",
    "gcc ./source/produtos/EditarProdutos.c -o dist/produtos/EditarProdutos",

    "gcc ./source/reclamacoes/MenuReclamacoes.c -o dist/reclamacoes/MenuReclamacoes",
    "gcc ./source/reclamacoes/CadastrarReclamacoes.c -o dist/reclamacoes/CadastrarReclamacoes",
    "gcc ./source/reclamacoes/VisualizarReclamacao.c -o dist/reclamacoes/VisualizarReclamacao",

    "gcc ./source/funcionarios/MenuFuncionarios.c -o dist/funcionarios/MenuFuncionarios",
    "gcc ./source/funcionarios/CadastrarFuncionario.c -o dist/funcionarios/CadastrarFuncionario",
    "gcc ./source/funcionarios/VisualizarFuncionario.c -o dist/funcionarios/VisualizarFuncionario",
    "gcc ./source/funcionarios/ExcluirFuncionario.c -o dist/funcionarios/ExcluirFuncionario",

    "gcc ./source/relatorios/MenuRelatorios.c -o dist/relatorios/MenuRelatorios",
    "gcc ./source/relatorios/VisualizarRelatorios.c -o dist/relatorios/VisualizarRelatorios",
    "gcc ./source/relatorios/RelatoriosDiarios.c -o dist/relatorios/RelatoriosDiarios",
    "gcc ./source/relatorios/RelatoriosMensais.c -o dist/relatorios/RelatoriosMensais",

    "gcc ./source/operacional/MenuEstoque.c -o dist/operacional/MenuEstoque",
    "gcc ./source/operacional/EditarEstoque.c -o dist/operacional/EditarEstoque",
    "gcc ./source/operacional/VisualizarEstoque.c -o dist/operacional/VisualizarEstoque",

    "gcc ./source/fechamento/RelatorioDiario.c -o dist/fechamento/RelatorioDiario",
];


gulp.task('default', async function(){
    builds.forEach((build)=>{
        exec(build, function(stdout, stderr){
            //console.log(stdout);
            //console.log(stderr);
        });
    });
});

