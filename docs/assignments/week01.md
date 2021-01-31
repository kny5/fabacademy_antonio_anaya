# 1. Principles and practices

For this week our assignments are to make a GIT tutorial following the quick review we had on Wednesday and define a final project. The final project is where, we individually or cooperatively apply our learned skills during the Fab-Academy.



## Git tutorial

I'm right now using Fedora 33 as main OS. Based on my research over the work of students on previous years I've found that showing terminal sessions has been something that a lot had struggle with. For this reason I'd like to share ASCIINEMA and I hope that anyone looking at this founds this tutorial useful. Then I'd like to show how I'm using GIT and GitLab to manage my repository and for that my entire project. Finally, I've found also that having a defined nomenclature or norm while writing commits is really useful for project management and maintenance.



### Setting up:

I'm a big fan of the Python Conda distribution, having a separated environment for each project keeps everything clean and easy on the system, so first:

Install Python Conda distribution. (instructions on this link)

Conda is an environment manager for a variety of scientific languages and toolkits including Python.

To create a Python evironment for your fab academy repository:
```
conda create -n fabacademy
```
To access this environment:
```
conda activate fabacademy
```
To deactivate and use the "base" environment:
```
conda deactivate
```
The next steps are related to asciinema to share a terminal session but beautifully:
(the conda environment should be activated already to keep everything in order)

Asciinema is a platform for beautifully sharing of terminal sessions.

Under Linux to install Asciinema I'm using Conda, and Python's PIP a package manager for the Python ecosystem.
```
pip install asciinema
```
Once asciinema is installed, you can start recording terminal sessions, to exit and finish the recording just write down "exit"
```
asciinema rec -t "fabacademy first assignment"
```



### Result:

<script id="asciicast-vzb1DXZk5KdnGWwGl1PL9mJt6" src="https://asciinema.org/a/vzb1DXZk5KdnGWwGl1PL9mJt6.js" async data-autoplay="true" data-size="medium" data-loop=1 data-t=23 data-speed=2  data-rows=10></script>



### Using Git:

Git is a Version Control Software, this means you can save different states of a repository, get back to one of those states with the pourpose of recovering from a bug, a crash a change of style while writting the code, change of paradigm or approach, these are things that happen while developing software.

We as students from the Fab Academy started with a boilerplate bootstrapped repository with a basic information architecture and Continuos Integration that renders the changes on our Markdown code to an Online Static Generated site.

But if you need a new repository managed with Git you just need to execute this on your terminal:
```
git init
```
I've made a recording showing the process of creating a directory, initianting a git repository, creating an empty file, add files to the git registry, commiting changes and trying to push. Since I don't have a remote repository it gave me a error. Which means I'd need to add a remote location on the following steps.

<script id="asciicast-QRUGeTxDm9O8XSR2KMVx7SHHE" src="https://asciinema.org/a/QRUGeTxDm9O8XSR2KMVx7SHHE.js"  data-autoplay="true" data-size="medium" data-loop=1 data-t=23 data-speed=2  data-rows=10></script>



### Clonning our Fab Academy repository:

The process of clonning a repository is just to create a new instance or copy of our MASTER repository in GitLab, this has the pourpose to avoid making changes everytime online and instead work on our local instance or copy and then syncronize the changes to the online repository, and this is the whole pourpose of Git, to manage changes simultaneously that happen when working colectively on big software projects.

You can add a SSH key to GitLab's repository configuration or you can just make use of the http request logging system.

During our Bootcamp we had the time to learn how to setup a SSH key on our systems and then copy the resulting string to the GitLab configuration to allow SSH clonning for ourselves.
```
ssh-keygen -t rsa -b 4096 -C "replace_with_@your_email.com"
```
After generating the key and saving it on a file, we proceed to copy the content of it it to our GitLab add SSH key input, we just need to be carefull to not add any space or any other content to it.

[Follow this tutorial from GitLab for detailed instructions.](https://docs.gitlab.com/ee/ssh/ "Follow this tutorial from GitLab.")

After this is setup You'll be able to excute succesuflly the next command:
```
git clone git@gitlab.fabcloud.org:your/project/path.git
```
Or using the http clonning approach:
```
git clone your_repository_url_on_fabcloud.git
```



### Serve mkdocs locally:

Mkdocs is the current Markdown to site generator, and the default choice for the Fab Academy boostrap site, for developing pourposes it's better to serve the repository locally before pushing to production or MASTER branch in the actual online Gitlab repository.

To install mkdocs we need also need two package dependencies:
```
pip install mkdocs mkdocs-material git-revision-date-localized
```
After those dependencies are installed we can render the Markdown files to html using, on terminal you need to access the directory where the mkdocs.yml, it means we need to access to our repository, in every system we can do it by using the "cd" command like this:
```
cd repository_name
```
To list all files inside the current location (Linux):
```
ls -ls
```
Then:
```
mkdocs build
```
I'd like to use Python's http server module instead of the default mkdoc serve, so ona second terminal or using TMUX and accessing the repository as we did before:
```
python -m http.server
```
And by default the page will be served at http://localhost:8000, and everytime we make a change at the site we need to execute mkdocs build as we did before.



### Working with the files:

I'm using Typora editor as I find it simple and aesthetic for Markdown editing.
The workflow is just to edit the files as Markdown, execute mkdocs and commit the changes on git.
