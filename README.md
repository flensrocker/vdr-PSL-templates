vdr-PSL-templates
=================

Why VDR P(lugin) S(hared) (L)ibraries? Because several VDR plugins keep re-inventing the
wheel on several matters, in fact for solving the very same problems they encounter, over and over
again. Therefore it should be possible to direct these efforts in some more synergic way towards more robustly
written plugins, and solving common problems in just one place should be one way to achieve this.
So this is code which still belongs to the VDR plugins scope and not necessarily into core VDR.
If something makes sense to be solved in core VDR, then Klaus Schmidinger, the VDR author should be contacted and
convinced for an API change, but that's another matter, this here is about plugin code.


[vdr-psl-funcxy](https://github.com/lucianm/vdr-PSL-templates/tree/master/vdr-psl-funcxy)
-----------------------------------------------------------------------------------------

This is just a sample shared library, specialized in some VDR specific (yet fictive) "functionality XY"
which several VDR plugins used to implement by themselves, so it's intended to be used in common by those plugins.
It is built against a specific VDR version, which means it has "VDR knowledge", it is only useful
to VDR plugins, so that's why it is somehow actually disguised as a VDR plugin:
- installed along with the VDR plugins;

- uses a different naming convention, to not be mistakenly loaded as an actual plugin (it does NOT enherit cPlugin);

- installs its own API export headers in a subfolder under the VDR header directory;

- installs it's own vdr-psl-funcxy.pc pkgconfig file for easyer integrating in consuming plugins;

- has to be built obviously before the plugins, this has to be achieved by the packager on systems
where VDR and plugins are built and then installed as distinct packages, or by [applying the
Makefile patch to the VDR sources](https://github.com/lucianm/vdr-PSL-templates/blob/master/patch-vdr-LCLBLD/vdr-1.7.42_PSL-Makefile.diff)
for those who have to build in the VDR source tree;


[vdr-usingpls](https://github.com/lucianm/vdr-PSL-templates/tree/master/vdr-usingpsl)
-------------------------------------------------------------------------------------

This is an actual sample VDR plugin which really builds against and uses (fictive) functionality from the
vdr-psl-funcxy above. It only has to be built after the PSL, and if building inside a VDR source tree,
the [VDR Makefile must have been patched](https://github.com/lucianm/vdr-PSL-templates/blob/master/patch-vdr-LCLBLD/vdr-1.7.42_PSL-Makefile.diff) for this.


How to generate a new PSL
-------------------------

- generate a new plugin called "newplugin";

- copy [the patch vdr-psl-funcxy.diff](https://github.com/lucianm/vdr-PSL-templates/blob/master/diffs-from-newplugin/vdr-psl-funcxy.diff)
into the newplugin directory;

- edit that patch and use search & replace for:
    - "funcxy" as a PSL name, give it a proper name reflecting the functionality of your PSL;

    - do the same with the namespace "PslFuncXy";

- now you can apply that patch with -p1 inside the directory;

- rename your just patched "newplugin" to "psl-YOURPSLNAME" and that's it, you can start writing your shared library;

- if your PSL needs itself specific other libs, make sure to add them under LIBPSL in your Makefile, that way, also the consuming plugins will get them;


How to generate a new plugin using the PSL
------------------------------------------

- generate a new plugin called "newplugin";

- copy [the patch vdr-usingpsl.diff](https://github.com/lucianm/vdr-PSL-templates/blob/master/diffs-from-newplugin/vdr-usingpsl.diff)
into the newplugin directory;

- edit that patch and use search & replace for:
    - "funcxy" as the template PSL name to replace with YOURPSLNAME you've given to your PSL;

    - do the same with the namespace "PslFuncXy" or just remove the dummy member PslFuncXy::cMyClass;

    - and the most important, replace "usingpsl" whith the name of your plugin;

- now you can apply that patch with -p1 inside the directory;

- rename your just patched "newplugin" to "YOURPLUGINNAME" and that's it, your plugin should build against the PSL;


How to convert an existing plugin to use a PSL
----------------------------------------------

Just consider [the differences in the Makefile](https://github.com/lucianm/vdr-PSL-templates/blob/master/diffs-from-newplugin/vdr-usingpsl.diff),
then you cand use code from the PSL you modified the Makefile for, where you include that PSL's export header.


How to add a PSL to a plugin which already uses one
---------------------------------------------------

Just as for the first PSL, add the differences considering the new name, so yet a new line for parsing the pkgconfig file,
and use it in the LIBS and LDFLAGS of your plugin, include the export header of the new PSL where you need it.

Have phun!
