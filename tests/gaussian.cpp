#include "emcee++.hpp"
using namespace std;
using namespace imcmc;

struct Gaussian{   //  test model
    imcmc_double p;

    void AddParam( imcmc_vector_string& param ){
        imcmc_vector_string_iterator it = param.begin();
        while( it != param.end() ){
            p[*it] = 0;
            ++it;
        }
    }

    void Update( imcmc_double full_param ){
        imcmc_double_iterator it = p.begin();
        while( it != p.end() ){
            p[it->first] = full_param[it->first];
            ++it;
        }
    }

    double GD(){
        double chisq = 0;
        imcmc_double_iterator it = p.begin();
        double i=1;
        while( it != p.end() ){
            chisq += p[it->first]*p[it->first]/(i*i);
            i += 1.;
            ++it;
        }
        return chisq;
    }
};

double TestLike( imcmc_double& full_param, double& lndet, double& chisq, void* model, void* data ){
    Gaussian *g = static_cast<Gaussian *>(model);
    g->Update(full_param);  //  now the model is workable

    chisq = g->GD();
    return -0.5*chisq;
}

int main( int argc, char *argv[] )
{
    MPI::Init(argc, argv);

    emcee_workspace ew;

    imcmc_vector_string param;
    param.push_back("x");
    param.push_back("y");
    param.push_back("z");

    Gaussian g;
    g.AddParam(param);

    ew.add_likelihood( TestLike, param, &g, NULL );
    ew.init("gaussian.ini");
    ew.do_sampling();

    MPI::Finalize();

}
