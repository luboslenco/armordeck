const project = new Project('ArmorDeck');

await project.addProject('Kinc');

project.addFile('Sources/**');
project.addFile('../esp32/main/doom/**');
project.addIncludeDir('../esp32/main');
project.addIncludeDir('../esp32/main/doom');
project.setDebugDir('Deployment');

project.addDefine('DOOM_TINY');
project.addDefine('DOOM_HALFRES');

project.flatten();

resolve(project);
