//
// Created by robert on 21.04.18.
//

#ifndef PN_LAB_EXAMPLE_LOGSETUP_H
#define PN_LAB_EXAMPLE_LOGSETUP_H

#define verbousePrint(cfg,...) if(cfg.verbose){print(cfg,__VA_ARGS__);}

#define verbouseFprint(cfg,stream,...) if(cfg.verbose){fprintf(stream,__VA_ARGS__);}

#define print(cfg,...) if(!cfg.quiet){printf(__VA_ARGS__);}
#define fprint(cfg,stream,...) if(!cfg.quiet){fprintf(stream,__VA_ARGS__);}

#endif //PN_LAB_EXAMPLE_LOGSETUP_H
